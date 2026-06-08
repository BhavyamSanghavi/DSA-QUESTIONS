1class Solution {
2public:
3    vector<int> pivotArray(vector<int>& nums, int pivot) {
4        vector<int>ans;
5        for(int i:nums) if(i<pivot) ans.push_back(i);
6        for(int i:nums) if(i==pivot) ans.push_back(i);
7        for(int i:nums) if(i>pivot) ans.push_back(i);
8        return ans;
9    }
10};