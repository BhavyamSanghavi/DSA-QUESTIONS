//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        int n = image.size(), m = image[0].size();
    if (image[sr][sc] == newColor) return image; // Edge case: no need to process if the starting cell is already the new color

    queue<pair<int, int>> q; // row, col
    q.push({sr, sc});
    int oldColor = image[sr][sc];
    image[sr][sc] = newColor; // Mark the starting cell with the new color
    
    while (!q.empty()) {
        int i = q.front().first, j = q.front().second;
        q.pop();
        
        // Check the 4 adjacent directions and process valid nodes
        if (i + 1 < n && image[i + 1][j] == oldColor) {
            image[i + 1][j] = newColor; // Update the color before pushing to queue
            q.push({i + 1, j});
        }
        if (i - 1 >= 0 && image[i - 1][j] == oldColor) {
            image[i - 1][j] = newColor;
            q.push({i - 1, j});
        }
        if (j + 1 < m && image[i][j + 1] == oldColor) {
            image[i][j + 1] = newColor;
            q.push({i, j + 1});
        }
        if (j - 1 >= 0 && image[i][j - 1] == oldColor) {
            image[i][j - 1] = newColor;
            q.push({i, j - 1});
        }
    }
    
    return image;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends