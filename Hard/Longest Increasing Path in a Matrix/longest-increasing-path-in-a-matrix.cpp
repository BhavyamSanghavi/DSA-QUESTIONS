//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     int dx[4]={1,-1,0,0};
     int dy[4]={0,0,1,-1};
    int f(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp)
    {
        int n=grid.size();
        int m=grid[0].size();
    
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        for(int k=0;k<=3;k++)
        {
            int x=i+dx[k];
            int y=j+dy[k];
            if(x<0 || x>=n || y<0 || y>=m) continue;
            if(grid[i][j]<grid[x][y])
            ans=max(ans,f(x,y,grid,dp));
        }
        return dp[i][j]=1+ans;
    }
    int longestIncreasingPath(vector<vector<int>>& grid, int n, int m) {
        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                 ans=max(ans,f(i,j,grid,dp));
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
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.longestIncreasingPath(matrix, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends