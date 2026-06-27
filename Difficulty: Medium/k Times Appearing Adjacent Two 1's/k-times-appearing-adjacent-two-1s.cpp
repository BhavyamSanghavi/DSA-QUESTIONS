class Solution {
  public:
    int dp[1001][1001][2];
    const int mod=1e9+7;
    
    int solve(int n, int k, int prev)
    {
        if(n==0 && k==0) return 1;
        if(n<0 || k<0) return 0;
        if(dp[n][k][prev]!=-1) return dp[n][k][prev]%mod;
        
        if(prev==1)
            return dp[n][k][prev]=(solve(n-1,k-1,1)%mod + solve(n-1,k,0)%mod)%mod;
        return dp[n][k][prev]=(solve(n-1,k,0)%mod + solve(n-1,k,1)%mod)%mod;
    }
    int countStrings(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(n,k,0);
    }
};