1class Solution {
2public:
3    int getCost(vector<vector<int>>& grid, int i, int j)
4    {
5        if(grid[i][j]==0) return 0;
6        else return 1;
7    }
8    int solve(vector<vector<int>>& grid, int k, int i, int j,vector<vector<vector<int>>>& dp)
9    {
10        if(i>=grid.size() || j>=grid[0].size() || k<0) return -1e9;
11        if(i==grid.size()-1 && j==grid[0].size()-1) 
12        {
13            if(k>=getCost(grid,i,j)) return grid[i][j];
14            else return -1e9;
15        }
16        if(dp[i][j][k]!=-1) return dp[i][j][k];
17        
18        int cost=getCost(grid,i,j);
19        int right=grid[i][j]+solve(grid,k-cost,i,j+1,dp);
20        int down=grid[i][j]+solve(grid,k-cost,i+1,j,dp);
21        return dp[i][j][k]=max(right,down);
22    }
23    int maxPathScore(vector<vector<int>>& grid, int k) {
24        vector<vector<vector<int>>>dp(grid.size()+1,vector<vector<int>>(grid[0].size()+1,vector<int>(k+1,-1)));
25        int ans=solve(grid,k,0,0,dp);
26        if(ans<0) return -1;
27        return ans;
28    }
29};
30