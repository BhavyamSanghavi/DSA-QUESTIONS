1class Solution {
2public:
3    string processStr(string s) {
4        string ans="";
5        for(char i:s)
6        {
7            if(i>='a' && i<='z') ans.push_back(i);
8            else if(i=='*' && ans.size()>0) ans.pop_back();
9            else if(i=='#') ans+=ans;
10            else reverse(ans.begin(),ans.end());
11        }
12        return ans;
13    }
14};