class Solution {
  public:
    int solve(vector<int>& a, vector<int>& b, int i, int j,vector<vector<int>>& dp)
    {
        if(j>=b.size()) return 0;
        if(i>=a.size()) return -1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int pick=a[i]*b[j]+solve(a,b,i+1,j+1,dp);
        int nopick=solve(a,b,i+1,j,dp);
        
        return dp[i][j]=max(pick,nopick);
    }
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        vector<vector<int>>dp(a.size()+1,vector<int>(b.size()+1,-1));
        return solve(a,b,0,0,dp);
    }
};
