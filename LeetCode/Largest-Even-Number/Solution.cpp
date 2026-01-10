1class Solution {
2public:
3    string largestEven(string s) {
4        int j=s.size()-1;
5        while(j>=0)
6        {
7            if(s[j--]=='1') s.pop_back();
8            else break;
9        }
10        return s;
11    }
12};