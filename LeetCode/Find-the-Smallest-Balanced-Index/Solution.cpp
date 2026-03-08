1class Solution {
2public:
3    
4    int smallestBalancedIndex(vector<int>& nums) {
5        int n = nums.size();
6
7        vector<long long> preSum(n,0);
8        vector<long long> sufProd(n,1);
9
10        for(int i=1;i<n;i++)
11            preSum[i] = preSum[i-1] + nums[i-1];
12
13        for(int i=n-2;i>=0;i--) 
14        {
15            if(sufProd[i+1] > LLONG_MAX / nums[i+1]) 
16                sufProd[i] = LLONG_MAX;   // prevent overflow
17            else
18                sufProd[i] = sufProd[i+1] * nums[i+1];
19        }
20
21        for(int i=0;i<n;i++)
22            if(preSum[i] == sufProd[i])
23                return i;
24
25        return -1;
26}
27};