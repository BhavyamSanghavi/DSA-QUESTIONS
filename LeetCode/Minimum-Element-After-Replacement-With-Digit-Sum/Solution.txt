1class Solution {
2public:
3    int replace(int n)
4    {
5        string num=to_string(n);
6        int sum=0;
7        for(int i=0;i<num.size();i++)
8            sum+=num[i]-'0';
9
10        return sum;
11    }
12    int minElement(vector<int>& nums) {
13        int ans=1e9;
14        for(int i=0;i<nums.size();i++)
15        {
16            nums[i]=replace(nums[i]);
17            ans=min(ans,nums[i]);
18        }
19        return ans;
20    }
21};