1class Solution {
2public:
3    long long factorial(int n) {
4        if (n < 0) return -1;
5
6        long long result = 1;
7        for (int i = 2; i <= n; ++i) 
8            result *= i;
9        return result;
10    }
11    bool isDigitorialPermutation(int n) {
12        long long sum=0;
13        string num=to_string(n);
14        for(int i=0;i<num.size();i++)
15        {
16            sum+=factorial(num[i]-'0');
17        }
18        string sums=to_string(sum);
19        sort(sums.begin(),sums.end());
20        sort(num.begin(),num.end());
21        return sums==num;
22    }
23};