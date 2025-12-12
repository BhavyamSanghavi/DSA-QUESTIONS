class Solution {
  public:
    void swapDiagonal(vector<vector<int>> &mat) {
        // code here
        int j=0;
        for(int i=0;i<mat.size();i++)
        {
            swap(mat[i][j],mat[i][mat.size()-j-1]);
            j++;
        }
    }
};
