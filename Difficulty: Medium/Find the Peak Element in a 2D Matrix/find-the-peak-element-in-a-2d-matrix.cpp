class Solution {
  public:
    bool isMaximum(vector<vector<int>>& mat, int i, int j)
    {
        if(i-1>=0 && mat[i][j]<mat[i-1][j]) return 0;
        if(j-1>=0 && mat[i][j]<mat[i][j-1]) return 0;
        if(i+1<mat.size() && mat[i][j]<mat[i+1][j]) return 0;
        if(j+1<mat[0].size() && mat[i][j]<mat[i][j+1]) return 0;
        return 1;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int>ans;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(isMaximum(mat,i,j)){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};
