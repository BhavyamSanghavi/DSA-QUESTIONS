class Solution {
  public:
    int dp[101][101];
    int solve(int l,int x)
    {
        if(l==0 || x==0) return 1;
        if(dp[l][x]!=-1) return dp[l][x];
        
        int cut=0;
        if(l>=x)
            cut=solve(l-x,x)*x;
        int nocut=solve(l,x-1);
        
        return dp[l][x]=max(cut,nocut);
    }
    int maxProduct(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,n-1);
    }
};