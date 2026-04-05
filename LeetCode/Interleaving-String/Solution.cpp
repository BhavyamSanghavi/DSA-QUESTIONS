1class Solution {
2public:
3    bool solve(string s1, string s2, string s3, int i, int j, int k,vector<vector<vector<int>>>& dp)
4    {
5        if(k>=s3.size()) return true;
6
7        if(s1[i]!=s3[k] && s2[j]!=s3[k]) return false;
8        if(dp[i][j][k]!=-1) return dp[i][j][k];
9
10        bool op1=false,op2=false;
11        if(i<s1.size() && s1[i]==s3[k])
12            op1=solve(s1,s2,s3,i+1,j,k+1,dp);
13        if(j<s2.size() && s2[j]==s3[k])
14            op2=solve(s1,s2,s3,i,j+1,k+1,dp);
15        
16        return dp[i][j][k]=op1 || op2;
17    }
18    bool isInterleave(string s1, string s2, string s3) {
19        int n=s1.size(),m=s2.size(),l=s3.size();
20        if(n+m!=l) return false;
21        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(l+1,-1)));
22        return solve(s1,s2,s3,0,0,0,dp);
23    }
24};