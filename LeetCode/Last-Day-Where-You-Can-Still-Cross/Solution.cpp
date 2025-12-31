1class Solution {
2public:
3    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
4        int left = 1, right = cells.size(), ans = 0;
5        while (left <= right) {
6            int mid = left + (right - left) / 2;
7            if (canWalk(cells, row, col, mid)) {
8                ans = mid;
9                left = mid + 1; 
10            } else right = mid - 1; 
11        }
12        return ans;
13    }
14    int DIR[5] = {0, 1, 0, -1, 0};
15    bool canWalk(vector<vector<int>>& cells, int row, int col, int dayAt) {
16        vector<vector<bool>> grid(row, vector<bool>(col, 0));
17        for (int i = 0; i < dayAt; ++i) grid[cells[i][0]-1][cells[i][1]-1] = 1;
18        queue<pair<int, int>> bfs;
19        for (int c = 0; c < col; ++c) {
20            if (grid[0][c] == 0) { // Add all valid start cells in the top row
21                bfs.push({0, c});
22                grid[0][c] = 1; // Mark as visited
23            }
24        }
25        while (!bfs.empty()) {
26            auto [r, c] = bfs.front(); bfs.pop();
27            if (r == row - 1) return true; // Reach to bottom -> Return Valid
28            for (int i = 0; i < 4; ++i) {
29                int nr = r + DIR[i], nc = c + DIR[i+1];
30                if (nr < 0 || nr == row || nc < 0 || nc == col || grid[nr][nc] == 1) continue;
31                grid[nr][nc] = 1; // Mark as visited
32                bfs.push({nr, nc});
33            }
34        }
35        return false;
36    }
37};