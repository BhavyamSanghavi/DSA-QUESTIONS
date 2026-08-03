1class Solution {
2public:
3    int countValidPrefixes(string s) {
4        int ans=0, one=0, zero=0;
5
6        for(int i=0;i<s.size();i++)
7        {
8            if(s[i]=='0') zero++;
9            else one++;
10
11            if(abs(one-zero)<=1) ans++;
12        }
13        return ans;
14    }
15};