1class Solution {
2public:
3    char processStr(string s, long long k) {
4        long long int n=0;
5        for(char i:s)
6            if(i>='a' && i<='z') n++;
7            else if(i=='#') n*=2;
8            else if(i=='*' && n>0) n--;
9        if(k>=n) return '.';
10
11        for(int i=s.size()-1;i>=0;i--)
12        {
13            if(isalpha(s[i]) && --n==k) return s[i];
14            else if(s[i]=='#')
15            {
16                n/=2;
17                if(k>=n) k-=n;
18            }
19            else if(s[i]=='%') k=n-1-k;
20            else if(s[i]=='*' && n>0) n++;
21        }
22        return '.';
23    }
24};