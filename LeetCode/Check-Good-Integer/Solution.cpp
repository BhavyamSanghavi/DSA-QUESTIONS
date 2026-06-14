1class Solution {
2public:
3    bool checkGoodInteger(int n) {
4        int digitsum=0,digitsquare=0;
5        while(n>0)
6        {
7            int d=n%10;
8            n/=10;
9            digitsum+=d;
10            digitsquare+=d*d;
11        }
12        return digitsquare-digitsum>=50;
13    }
14};