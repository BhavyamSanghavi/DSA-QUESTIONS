//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  void dfs(vector<vector<int>> &grid, int i,int j)
  {
      int n=grid.size(), m=grid[0].size();
      grid[i][j]=0;
      if(i+1<n && grid[i+1][j]==1) dfs(grid,i+1,j);
      if(j+1<m && grid[i][j+1]==1) dfs(grid,i,j+1);
      if(i-1>=0 && grid[i-1][j]==1) dfs(grid,i-1,j);
      if(j-1>=0 && grid[i][j-1]==1) dfs(grid,i,j-1);
  }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n=grid.size(), m=grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1) dfs(grid,i,0);
            if(grid[i][m-1]==1) dfs(grid,i,m-1);
        }
        for(int j=0;j<m;j++)
        {
            if(grid[0][j]==1) dfs(grid,0,j);
            if(grid[n-1][j]==1) dfs(grid,n-1,j);
        }
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)        
                if(grid[i][j]==1) ans++;
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends