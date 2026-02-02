1class Solution {
2public:
3    int finalElement(vector<int>& nums) {
4        return max(nums[0],nums[nums.size()-1]);
5    }
6};