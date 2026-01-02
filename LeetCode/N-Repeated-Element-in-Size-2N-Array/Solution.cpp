1class Solution {
2public:
3    int repeatedNTimes(vector<int>& nums) {
4        unordered_map<int,int>m;
5        for(int i:nums) m[i]++;
6        for(auto i:m) if(i.second==nums.size()/2) return i.first;
7        return 0;
8    }
9};