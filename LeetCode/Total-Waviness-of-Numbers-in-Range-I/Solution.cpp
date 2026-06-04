1class Solution {
2public:
3    int solve(string s)
4    {
5        if(s.size()<3) return 0;
6        int cnt=0;
7        for(int i=1;i<s.size()-1;i++)
8            if((s[i]>s[i+1] && s[i]>s[i-1]) || (s[i]<s[i+1] && s[i]<s[i-1]))
9                cnt++;
10        return cnt;
11    }
12    int totalWaviness(int num1, int num2) {
13        int ans=0;
14        for(int i=num1;i<=num2;i++)
15            ans+=solve(to_string(i));
16        return ans;
17    }
18};