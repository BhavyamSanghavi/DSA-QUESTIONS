1class Solution {
2public:
3    int firstUniqueFreq(vector<int>& nums) {
4        unordered_map<int,int>freq;
5        for(int i:nums) freq[i]++;
6        unordered_map<int,int>unq;
7        for(auto i:freq) unq[i.second]++;
8        for(int i:nums) 
9            if(unq[freq[i]]==1) return i;
10        return -1;
11    }
12};