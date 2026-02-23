1class Solution {
2public:
3    int scoreDifference(vector<int>& nums) {
4        int first=0,second=0;
5        bool flag=true;
6        for(int i=0;i<nums.size();i++)
7        {
8            if((i+1)%6==0) flag=!flag;
9            if(nums[i]%2==1) flag=!flag;
10            if(flag) first+=nums[i];
11            else second+=nums[i];
12        }
13        return first-second;
14    }
15};