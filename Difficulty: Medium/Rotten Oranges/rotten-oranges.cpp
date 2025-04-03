//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        
        queue<vector<int>>q;        // row, col, time
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==2) q.push({i,j,0});
        
        int t=0;
        while(!q.empty())    
        {
            int qs=q.size();
            
            for(int x=0;x<qs;x++)
            {
                int i=q.front()[0], j=q.front()[1]; t=q.front()[2]; q.pop();
                if(i+1<n && grid[i+1][j]==1) {q.push({i+1,j,t+1}); grid[i+1][j]=2;}
                if(i-1>=0 && grid[i-1][j]==1) {q.push({i-1,j,t+1}); grid[i-1][j]=2;}
                if(j+1<m && grid[i][j+1]==1) {q.push({i,j+1,t+1}); grid[i][j+1]=2;}
                if(j-1>=0 && grid[i][j-1]==1) {q.push({i,j-1,t+1}); grid[i][j-1]=2;}
            }
                // timer++;
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==1) return -1;
        
        return t;
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends