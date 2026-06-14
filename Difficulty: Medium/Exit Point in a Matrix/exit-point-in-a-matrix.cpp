class Solution {
  public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        int i = 0, j = 0;
        int index = 0;
        
        while (i >= 0 && i < mat.size() && j >= 0 && j < mat[0].size())
        {
            if (mat[i][j] == 0)
            {
                i += dir[index][0];
                j += dir[index][1];
            }
            else
            {
                mat[i][j] = 0;
                index = (index + 1) % 4;
                i += dir[index][0];
                j += dir[index][1];
            }
        }
        i-=dir[index][0];
        j-=dir[index][1];
        return {i, j};
    }
};