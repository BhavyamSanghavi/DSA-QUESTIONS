1class Solution {
2public:
3    vector<int> sortArrayByParity(vector<int>& nums) {
4        int start=0,end=nums.size()-1;
5        while(start<end)
6        {
7            if(nums[start]%2==0) start++;
8            else swap(nums[start],nums[end--]);
9        }
10        return nums;
11    }
12};