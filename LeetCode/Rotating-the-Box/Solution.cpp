1class Solution {
2public:
3    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
4        int ROWS = box.size();
5        int COLS = box[0].size();
6        
7        vector<vector<char>> res(COLS, vector<char>(ROWS, '.'));
8        
9        for (int r = 0; r < ROWS; r++) {
10            int i = COLS - 1;
11            for (int c = COLS - 1; c >= 0; c--) {
12                if (box[r][c] == '#') {
13                    res[i][ROWS - r - 1] = '#';
14                    i--;
15                }
16                else if (box[r][c] == '*') {
17                    res[c][ROWS - r - 1] = '*';
18                    i = c - 1;
19                }
20            }
21        }
22        
23        return res;
24    }
25};