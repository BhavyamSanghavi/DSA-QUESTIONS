1class Solution {
2public:
3    char calculateHash(string s)
4    {
5        int sum=0;
6        for(int i=0;i<s.size();i++)
7        {
8            int hash=s[i]-'a';
9            sum+=hash;
10        }
11        sum=sum%26;
12        return sum+'a';
13    }
14    string stringHash(string s, int k) {
15        string ans="";
16        for(int i=0;i<s.size();i+=k)
17        {
18            string t=s.substr(i,k);
19            ans+=calculateHash(t);
20        }
21        return ans;
22    }
23};