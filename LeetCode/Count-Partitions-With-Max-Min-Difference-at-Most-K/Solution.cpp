class Solution {
public:
    int mod = 1e9 + 7;
    typedef long long ll;

    ll solve(int ind, vector<int>& nums, int k) {
        int n = nums.size();
        if (ind == n) return 1;

        ll ways = 0;
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (int j = ind; j < n; ++j) {
            mini = min(mini, nums[j]);
            maxi = max(maxi, nums[j]);
            if (maxi - mini > k) break;
            ways = (ways + solve(j + 1, nums, k)) % mod;
        }
        return ways;
    }

    int countPartitions(vector<int>& nums, int k) {
        return solve(0, nums, k);
    }
};