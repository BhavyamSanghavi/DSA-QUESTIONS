1class Solution {
2public:
3    int maxDistance(string moves) {
4        int horizontal=0,vertical=0,additional=0;
5        for(char i:moves)
6        {
7            if(i=='L') horizontal++;
8            else if(i=='R') horizontal--;
9            else if(i=='U') vertical++;
10            else if(i=='D') vertical--;
11            else additional++;
12        }
13        return abs(horizontal)+abs(vertical)+additional;
14    }
15};