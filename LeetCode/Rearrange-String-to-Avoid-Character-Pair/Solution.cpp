1class Solution {
2public:
3    string rearrangeString(string s, char x, char y) {
4        int cnt=0;
5        string ans="";
6        for(char i:s)
7            if(i!=x) ans+=i;
8            else cnt++;
9        while(cnt--)
10            ans+=x;
11        
12        return ans;
13    }
14};