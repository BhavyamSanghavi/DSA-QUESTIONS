1class Solution {
2public:
3    vector<string> createGrid(int m, int n) {
4        string t="";
5        for(int i=0;i<n;i++) t+="#";
6        vector<string>grid(m,t);
7
8        for(int i=0;i<n;i++) grid[0][i]='.';
9        for(int i=0;i<m;i++) grid[i][n-1]='.';
10        return grid;
11    }
12};