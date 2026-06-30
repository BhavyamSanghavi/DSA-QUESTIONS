1class Solution {
2public:
3    int atMost(string s)
4    {
5        int ans=0,i=0;
6        int cntA=0, cntB=0,cntC=0;
7        for(int j=0;j<s.size();j++)
8        {
9            if(s[j]=='a') cntA++;
10            if(s[j]=='b') cntB++;
11            if(s[j]=='c') cntC++;
12            while(cntA>0 && cntB>0 && cntC>0)
13            {
14                if(s[i]=='a') cntA--;
15                if(s[i]=='b') cntB--;
16                if(s[i]=='c') cntC--;
17                i++;
18            }
19            ans+=i;
20        }
21        return ans;
22    }
23    int numberOfSubstrings(string s) {
24        return atMost(s);
25    }
26};