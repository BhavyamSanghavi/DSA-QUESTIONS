1class Solution {
2public:
3    void transpose(vector<vector<int>>& matrix)
4    {
5        for(int i=0;i<matrix.size();i++)
6        {
7            for(int j=i+1;j<matrix.size();j++)
8            {
9                swap(matrix[i][j],matrix[j][i]);
10            }
11        }
12    }
13    void rotate(vector<vector<int>>& matrix) {
14        transpose(matrix);
15        for(int i=0;i<matrix.size();i++)
16        {
17            int s=0,e=matrix.size()-1;
18            while(s<=e)
19            {
20                swap(matrix[i][s++],matrix[i][e--]);
21            }
22        }
23    }
24};