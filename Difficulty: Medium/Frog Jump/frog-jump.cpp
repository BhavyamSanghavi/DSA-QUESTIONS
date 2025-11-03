class Solution {
  public:
    int solve(vector<int>& height, int i, vector<int>& dp) {
    if(i == height.size() - 1) return 0;
    if(dp[i] != -1) return dp[i];
    
    int first = abs(height[i] - height[i+1]) + solve(height, i+1, dp);
    int second = INT_MAX;
    if(i + 2 < height.size())
        second = abs(height[i] - height[i+2]) + solve(height, i+2, dp);
    
    return dp[i] = min(first, second);
}

int minCost(vector<int>& height) {
    vector<int> dp(height.size(), -1);
    return solve(height, 0, dp);
}

};