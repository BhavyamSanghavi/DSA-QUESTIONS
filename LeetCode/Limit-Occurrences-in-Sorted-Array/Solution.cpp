1class Solution {
2public:
3    vector<int> limitOccurrences(vector<int>& nums, int k) {
4        vector<int>ans;
5        int i=0;
6        while(i<nums.size())
7        {
8            int ele=nums[i], freq=k;
9            while(i<nums.size() && nums[i]==ele && freq--)
10            {
11                ans.push_back(nums[i++]);
12            }
13            while(i<nums.size() && nums[i]==ele) i++;
14        }
15        return ans;
16    }
17};