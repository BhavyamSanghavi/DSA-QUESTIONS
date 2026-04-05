1class Solution {
2public:
3    bool judgeCircle(string moves) {
4        int x=0,y=0;
5        for(char i:moves)
6        {
7            if(i=='U') ++y;
8            else if(i=='D') --y;
9            else if(i=='L') --x;
10            else ++x;
11        }
12        return x==0 && y==0;
13    }
14};