1class Solution {
2public:
3    int firstStableIndex(vector<int>& nums, int k) {
4        int n=nums.size();
5        vector<int>premax(n), premin(n);
6        
7        int maxi=0;
8        for(int i=0;i<n;i++)
9        {
10            maxi=max(maxi,nums[i]);
11            premax[i]=maxi;
12        }
13        int mini=1e9;
14        for(int i=n-1;i>=0;i--)
15        {
16            mini=min(mini,nums[i]);
17            premin[i]=mini;
18        }
19
20        for(int i=0;i<n;i++)
21        {
22            int res=premax[i]-premin[i];
23            if(res<=k) return i;
24        }
25        return -1;
26    }
27};
28