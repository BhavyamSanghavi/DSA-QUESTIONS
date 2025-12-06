class Solution {
  public:
    int solve(vector<int>&arr, int i, int j,vector<vector<int>>& dp)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int first=arr[i]+min(solve(arr,i+2,j,dp),solve(arr,i+1,j-1,dp));
        int second=arr[j]+min(solve(arr,i,j-2,dp),solve(arr,i+1,j-1,dp));
        return dp[i][j]=max(first,second);
    }
    int maximumAmount(vector<int> &arr) {
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(arr,0,n-1,dp);
        
    }
};