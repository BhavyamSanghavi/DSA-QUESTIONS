class Solution {
  public:
    int solve(int i, int prev, vector<int>& arr,vector<vector<int>>& dp)
    {
        if(i>=arr.size()) return 0;
        if(dp[i][prev]!=-1) return dp[i][prev];
        
        int pick=0,nopick=0;
        if(arr[i]>prev)
            pick=arr[i]+solve(i+1,arr[i],arr,dp);
        nopick=solve(i+1,prev,arr,dp);
        
        return dp[i][prev]=max(pick,nopick);
    }
    int maxSumIS(vector<int>& arr) {
        int maxi=*max_element(arr.begin(),arr.end());
        vector<vector<int>>dp(arr.size(),vector<int>(maxi+1,-1));
        return solve(0,0,arr,dp);
        
    }
};