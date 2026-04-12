1class Solution {
2public:
3    vector<int> findDegrees(vector<vector<int>>& matrix) {
4        vector<int>ans(matrix.size());
5        for(int i=0;i<matrix.size();i++)
6        {
7            int degree=0;
8            for(int j=0;j<matrix[0].size();j++)
9                if(matrix[i][j]==1)
10                    degree++;
11            
12            ans[i]=degree;
13        }
14        return ans;
15    }
16};