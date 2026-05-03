1class Solution {
2public:
3    bool isPrime(int n) 
4    {
5        if (n <= 1) return false;
6        if (n <= 3) return true;
7
8        if (n % 2 == 0 || n % 3 == 0) return false;
9
10        for (int i = 5; i * i <= n; i += 6) 
11            if (n % i == 0 || n % (i + 2) == 0)
12                return false;
13
14        return true;
15    }
16    int sumOfPrimesInRange(int n) {
17        int sum=0;
18        string num=to_string(n);
19        while(num.back()==0) num.pop_back();
20        reverse(num.begin(),num.end());
21        int rev=stoi(num);
22
23        for(int i=min(n,rev);i<=max(n,rev);i++)
24            if(isPrime(i)) sum+=i;
25        return sum;
26    }
27};