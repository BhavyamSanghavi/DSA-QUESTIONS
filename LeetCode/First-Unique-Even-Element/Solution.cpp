1class Solution {
2public:
3    int firstUniqueEven(vector<int>& nums) {
4        unordered_map<int,int>m;
5        for(int i:nums) m[i]++;
6        for(int i:nums)
7            if(m[i]==1 && i%2==0) return i;
8        return -1;
9    }
10};