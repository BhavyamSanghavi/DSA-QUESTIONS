1class Solution {
2public:
3    long long maximumScore(vector<int>& nums) {
4        int n=nums.size();
5        vector<long long>prefix(n,nums[0]);
6        vector<int>suffix(n,nums[n-1]);
7        for(int i=1;i<n;i++)
8        {
9            prefix[i]=prefix[i-1]+nums[i];
10            suffix[n-i-1]=min(suffix[n-i],nums[n-i-1]);
11        }
12        long long sum=INT_MIN;
13        // for(auto i:prefix) cout<<i<<"  ";
14        // cout<<endl;
15        // for(auto i:suffix) cout<<i<<"  ";
16        for(int i=0;i<n-1;i++)
17        {
18            sum=max(sum,(long long)prefix[i]-suffix[i+1]);
19        }
20        return sum;
21    }
22};