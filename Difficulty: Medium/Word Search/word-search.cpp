class Solution {
  public:
    bool solve(vector<vector<char>>& mat, string &word, int i, int j, int index)
    {
        if(index>=word.size()) return true;
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size()) return false;
        if(mat[i][j]!=word[index]) return false;
        
        char temp=mat[i][j];
        mat[i][j]='.';
        bool up=solve(mat,word,i-1,j,index+1);
        bool down=solve(mat,word,i+1,j,index+1);
        bool left=solve(mat,word,i,j-1,index+1);
        bool right=solve(mat,word,i,j+1,index+1);
        
        mat[i][j]=temp;
        return up||down||left||right;
    }
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==word[0] && solve(mat,word,i,j,0))
                    return true;
            }
        }
        return false;
    }
};