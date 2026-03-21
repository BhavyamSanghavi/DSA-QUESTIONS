1class Solution {
2public:
3    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
4        int start=x,end=x+k-1;
5        while(start<end)
6        {
7            for(int i=y;i<y+k;i++)
8                swap(grid[start][i],grid[end][i]);
9
10            start++;
11            end--;
12        }
13        return grid;
14    }
15};