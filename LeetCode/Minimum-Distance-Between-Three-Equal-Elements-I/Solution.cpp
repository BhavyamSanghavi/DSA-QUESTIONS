1class Solution {
2public:
3    int minimumDistance(vector<int>& nums) {
4        int ans=INT_MAX;
5        if(nums.size()<3) return -1;
6        for(int i=0;i<nums.size()-2;i++)
7        {
8            for(int j=i+1;j<nums.size()-1;j++)
9            {
10                for(int k=j+1;k<nums.size();k++)
11                {
12                    if(nums[i]==nums[j] && nums[i]==nums[k])
13                    {
14                        ans=min(ans,abs(i-j)+abs(j-k)+abs(i-k));
15                    }
16                }
17            }
18        }
19        if(ans==INT_MAX) return -1;
20        return ans;
21    }
22};