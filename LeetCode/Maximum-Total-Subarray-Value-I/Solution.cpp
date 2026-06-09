1class Solution {
2public:
3    long long maxTotalValue(vector<int>& nums, int k) {
4        int maxi=*max_element(nums.begin(),nums.end());
5        int mini=*min_element(nums.begin(),nums.end());
6        int val=maxi-mini;
7        return (long long)val*k;
8    }
9};