1class Solution {
2public:
3    unordered_map<int,vector<int>>m;
4    Solution(vector<int>& nums) {
5        for(int i=0;i<nums.size();i++)
6            m[nums[i]].push_back(i);
7    }
8    
9    int pick(int target) {
10        vector<int>v=m[target];
11        return v[rand()%v.size()];
12    }
13};
14
15/**
16 * Your Solution object will be instantiated and called as such:
17 * Solution* obj = new Solution(nums);
18 * int param_1 = obj->pick(target);
19 */