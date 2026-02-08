1class Solution {
2public:
3    vector<long long> mergeAdjacent(vector<int>& nums) {
4        vector<long long>ans;
5        ans.push_back(nums[0]);
6        for(int i=1;i<nums.size();i++)
7        {
8            long long val=nums[i];
9            while(ans.size()>0 && ans.back()==val)
10            {
11                val+=ans[ans.size()-1];
12                ans.pop_back();
13            }
14            ans.push_back(val);
15        }
16        return ans;
17    }
18};