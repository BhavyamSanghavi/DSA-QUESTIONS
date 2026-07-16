1class Solution {
2public:
3    long long gcdSum(vector<int>& nums) {
4        vector<int>prefixGcd(nums.size());
5        int mx=-1;
6        
7        for(int i=0;i<nums.size();i++)
8        {
9            mx=max(mx,nums[i]);
10            prefixGcd[i]=gcd(nums[i],mx);
11        }
12        
13        sort(prefixGcd.begin(),prefixGcd.end());
14        
15        long long ans=0;
16        int i=0,j=prefixGcd.size()-1;
17        
18        while(i<j)
19            ans+=gcd(prefixGcd[i++],prefixGcd[j--]);
20        
21        return ans;
22    }
23};