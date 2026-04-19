1class Solution {
2public:
3    int firstStableIndex(vector<int>& nums, int k) {
4        for(int i=0;i<nums.size();i++)
5        {
6            int maxi=*max_element(nums.begin(),nums.begin()+i);
7            int mini=*min_element(nums.begin()+i,nums.end());
8            if(maxi-mini<=k) return i;
9        }
10        return -1;
11    }
12};