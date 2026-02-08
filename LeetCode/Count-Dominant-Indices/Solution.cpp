1class Solution {
2public:
3    int dominantIndices(vector<int>& nums) {
4        int sum=nums[nums.size()-1];
5        int n=1,ans=0;
6        for(int i=nums.size()-2;i>=0;i--)
7        {
8            double avg=sum/n;
9            if(nums[i]>avg) ans++;
10            sum+=nums[i];
11            n++;
12        }
13        return ans;
14    }
15};