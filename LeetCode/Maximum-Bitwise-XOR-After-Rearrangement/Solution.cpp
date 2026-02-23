1class Solution {
2public:
3    string maximumXor(string s, string t) {
4        int one=0,zero=0;
5        string ans="";
6        for(char i:t)
7            if(i=='0') ++zero;
8            else ++one;
9        for(char i:s)
10        {
11            if(i=='0')
12            {
13                if(one)
14                {
15                    --one;
16                    ans.push_back('1');
17                }
18                else
19                {
20                    --zero;
21                    ans.push_back('0');
22                }
23            }
24            else
25            {
26                if(zero)
27                {
28                    --zero;
29                    ans.push_back('1');
30                }
31                else
32                {
33                    --one;
34                    ans.push_back('0');
35                }
36            }
37        }
38        return ans;
39    }
40};