//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  bool isSafe(vector<vector<int>>& grid, vector<vector<bool>> &vis, int row, int col, int x, int y, string &temp){
        if(x>=0 && x<row && y>=0 && y<col && grid[x][y] && !vis[x][y]) return true;
        temp+="E"; //Island formed
        return false;
        
    }
    
    void dfs(vector<vector<int>>& grid, vector<vector<bool>> &vis, int row, int col, int x, int y, string &temp){
        
        vis[x][y]= true;
        
        // down
        if(isSafe(grid, vis, row, col, x+1,y, temp)){
            temp+= 'D';
            dfs(grid, vis, row, col, x+1,y, temp);
        }
        //up
        if(isSafe(grid, vis, row, col, x-1,y, temp)){
            temp+= 'U';
            dfs(grid, vis, row, col, x-1,y, temp);
        }
        //left
        if(isSafe(grid, vis, row, col, x,y-1, temp)){
            temp+= 'L';
            dfs(grid, vis, row, col, x,y-1, temp);
        }
        //right
        if(isSafe(grid, vis, row, col, x,y+1, temp)){
            temp+= 'R';
            dfs(grid, vis, row, col, x,y+1, temp);
        }
        
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n= grid.size(), m= grid[0].size();
        
        unordered_set<string> st;
        
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]==1 && !vis[i][j]){
                    string temp="S";
                    dfs(grid, vis,n, m, i, j, temp);
                    st.insert(temp);
                }
            }
        }
        
        return st.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends