1class Solution {
2public:
3    long long solve(vector<int>& nums1, vector<int>& nums2, int k, int i, int j,vector<vector<vector<long long>>>& dp)
4    {
5        if(k==0) return 0;
6        if(i>=nums1.size() || j>=nums2.size()) return -1e18;
7        if(dp[i][j][k]!=-1) return dp[i][j][k];
8
9        long long op1=(long long)nums1[i]*nums2[j]+solve(nums1,nums2,k-1,i+1,j+1,dp);
10        long long op2=solve(nums1,nums2,k,i+1,j,dp);
11        long long op3=solve(nums1,nums2,k,i,j+1,dp);
12
13        return dp[i][j][k]=max({op1,op2,op3});
14    }
15    long long maxScore(vector<int>& A, vector<int>& B, int k)
16{
17    int n = A.size(), m = B.size();
18
19    const long long NEG = -1e18;
20
21    vector dp(n+1,
22        vector(m+1,
23            vector<long long>(k+1, NEG)));
24
25    // base
26    for(int i=0;i<=n;i++)
27        for(int j=0;j<=m;j++)
28            dp[i][j][0] = 0;
29
30    for(int i=1;i<=n;i++)
31    {
32        for(int j=1;j<=m;j++)
33        {
34            for(int t=1;t<=k;t++)
35            {
36                long long take =
37                    dp[i-1][j-1][t-1] +
38                    (long long)A[i-1]*B[j-1];
39
40                long long skip1 = dp[i-1][j][t];
41                long long skip2 = dp[i][j-1][t];
42
43                dp[i][j][t] = max({take, skip1, skip2});
44            }
45        }
46    }
47
48    return dp[n][m][k];
49}
50
51};