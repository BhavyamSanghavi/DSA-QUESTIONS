1class Solution {
2public:
3    vector<long long> findPrefixScore(vector<int>& nums) {
4        int maxi=nums[0], n=nums.size();
5        vector<long long>ans(n,0);
6        
7        ans[0]=nums[0]*2;
8        for(int i=1;i<n;i++)
9        {
10            maxi=max(maxi,nums[i]);
11            ans[i]=ans[i-1]+nums[i]+maxi;
12        }
13        return ans;
14    }
15};