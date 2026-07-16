class Solution {
  public:
    int solve(int n, int sum, vector<vector<int>>& dp)
    {
        if(n==0 && sum==0) return 1;
        if(sum==0 && n>0) return 0;
        if(sum<0 || n<=0) return 0;
        
        if(dp[n][sum]!=-1) return dp[n][sum];
        
        int i=0;
        if(n==1) i=1;
        
        int ans=0;
        for(int k=i;k<=9;k++)
            ans+=solve(n-1,sum-k,dp);
        
        return dp[n][sum]=ans;
    }
    int countWays(int n, int sum) {
        if(n*9<sum) return -1;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(n,sum,dp);
    }
};