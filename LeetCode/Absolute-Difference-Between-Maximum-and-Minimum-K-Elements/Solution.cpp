1class Solution {
2public:
3    int absDifference(vector<int>& nums, int k) {
4        sort(nums.begin(),nums.end());
5        int minsum=0,maxsum=0;
6        int i=0,j=nums.size()-1;
7        while(k--)
8        {
9            minsum+=nums[i++];
10            maxsum+=nums[j--];
11        }
12        return maxsum-minsum;
13    }
14};