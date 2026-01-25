1class Solution {
2public:
3    int minimumPrefixLength(vector<int>& nums) {
4        int ans=nums.size();
5        for(int i=nums.size()-1;i>0;i--)
6        {
7            if(nums[i]>nums[i-1]) ans--;
8            else break;
9        }
10        return ans-1;
11    }
12};