1class Solution {
2public:
3
4struct State {
5    int i;
6    long long num, den;
7
8    bool operator<(const State& other) const {
9        return tie(i,num,den) < tie(other.i,other.num,other.den);
10    }
11};
12
13long long solve(vector<int>& nums, long long k, int i,
14                long long num, long long den,
15                map<State,long long>& dp)
16{
17    if(i == nums.size())
18        return (den == 1 && num == k);
19
20    State s{i,num,den};
21    if(dp.count(s)) return dp[s];
22
23    long long ans = 0;
24
25    // multiply
26    {
27        long long n = num * nums[i];
28        long long d = den;
29        long long g = gcd(llabs(n), llabs(d));
30        ans += solve(nums,k,i+1,n/g,d/g,dp);
31    }
32
33    // divide
34    {
35        long long n = num;
36        long long d = den * nums[i];
37        long long g = gcd(llabs(n), llabs(d));
38        ans += solve(nums,k,i+1,n/g,d/g,dp);
39    }
40
41    // skip
42    ans += solve(nums,k,i+1,num,den,dp);
43
44    return dp[s] = ans;
45}
46
47long long countSequences(vector<int>& nums, long long k) {
48    map<State,long long> dp;
49    return solve(nums,k,0,1,1,dp);
50}
51};