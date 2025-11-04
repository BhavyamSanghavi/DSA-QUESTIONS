class Solution {
  public:
    int minSquares(int n) {
        // Code here
        vector<int> dp(n+1,INT_MAX);
    dp[0]=0;
    
    int ans;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i-j*j>=0)
            dp[i]=min(dp[i],1+dp[i-j*j]);
        }
        ans=dp[i];
    }
    return ans;
    }
};