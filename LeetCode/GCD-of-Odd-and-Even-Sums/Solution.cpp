1class Solution {
2public:
3    int gcdOfOddEvenSums(int n) {
4        int sumOdd=0, sumEven=0, k=n;
5        int i=1;
6        while(k--)
7        {
8            sumOdd+=i;
9            i+=2;
10        }
11        k=n;
12        i=2;
13        while(k--)
14        {
15            sumEven+=i;
16            i+=2;
17        }
18
19        return __gcd(sumOdd,sumEven);
20    }
21};