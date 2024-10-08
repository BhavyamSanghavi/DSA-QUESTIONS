//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void solve(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& vis)
    {
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0) return;
        if(grid[i][j]=='0' || vis[i][j]==true) return;
        if(grid[i][j]=='1' && !vis[i][j])
        {
            vis[i][j]=true;
            solve(grid,i-1,j,vis);
            solve(grid,i+1,j,vis);
            solve(grid,i,j-1,vis);
            solve(grid,i,j+1,vis);
            solve(grid,i-1,j+1,vis);
            solve(grid,i+1,j+1,vis);
            solve(grid,i+1,j-1,vis);
            solve(grid,i-1,j-1,vis);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    solve(grid,i,j,vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends