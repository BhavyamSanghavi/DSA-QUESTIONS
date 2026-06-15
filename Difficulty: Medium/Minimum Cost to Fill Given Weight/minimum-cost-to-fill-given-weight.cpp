class Solution {
  public:
    int solve(vector<int>& cost, int buy, int i, vector<vector<int>>& dp)
    {
        if(buy==0) return 0;
        if(buy<0 || i>=cost.size()) return 1e9;
        if(dp[buy][i]!=-1) return dp[buy][i];
        
        if(cost[i]==-1) return solve(cost,buy,i+1,dp);
        
        int addNext=solve(cost,buy-i-1,i+1,dp);
        int addSame=solve(cost,buy-i-1,i,dp);
        
        if(addNext!=1e9) addNext+=cost[i];
        if(addSame!=1e9) addSame+=cost[i];
        
        int moveNext=solve(cost,buy,i+1,dp);
        
        return dp[buy][i]=min({addNext,addSame,moveNext});
    }
    int minimumCost(vector<int> &cost, int w) {
        vector<vector<int>>dp(w+1,vector<int>(cost.size()+1,-1));
        int ans=solve(cost,w,0,dp);
        return ans==1e9 ? -1:ans;
    }
};
