1class Solution {
2public:
3    vector<int> concatWithReverse(vector<int>& nums) {
4        int i=nums.size()-1;
5        while(i>=0) nums.push_back(nums[i--]);
6        return nums;
7    }
8};