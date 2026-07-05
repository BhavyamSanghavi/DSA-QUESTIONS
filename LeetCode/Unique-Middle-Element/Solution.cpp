1class Solution {
2public:
3    bool isMiddleElementUnique(vector<int>& nums) {
4        unordered_map<int,int>m;
5        for(int i:nums) m[i]++;
6        return m[nums[nums.size()/2]]==1;
7    }
8};