class Solution {
  public:
    bool find(vector<vector<int>> &mat2, int sum)
    {
        int i=0,j=mat2.size()-1;
        while(i<mat2.size() && j>=0)
        {
            if(mat2[i][j]==sum) return 1;
            else if(mat2[i][j]<sum) i++;
            else j--;
        }
        return 0;
    }
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        int ans=0;
        for(int i=0;i<mat1.size();i++)
        {
            for(int j=0;j<mat1.size();j++)
            {
                int req=x-mat1[i][j];
                if(find(mat2,req)) ans++;
            }
        }
        return ans;
    }
};