class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        //store coordinates as per value
        vector<pair<int,int>> pos[201];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                pos[matrix[i][j]].push_back({i, j});
            }
        }

        int ans = 0;
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {

                int x = matrix[r][c];
                if(x == 0) continue;

                bool ok = true;

                // only check values > x
                for(int val = x + 1; val <= 200 && ok; val++) {
                    for(auto &[nr, nc] : pos[val]) {

                        int dr = abs(nr - r);
                        int dc = abs(nc - c);

                        // must lie inside square
                        if(dr <= x && dc <= x) {
                            // ignore corners
                            if(dr == x && dc == x) continue;
                            ok = false;
                            break;
                        }
                    }
                }

                if(ok) ans++;
            }
        }

        return ans;
    }
};