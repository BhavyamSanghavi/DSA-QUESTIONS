1class Solution {
2public:
3    int minOperations(string s) {
4        int ans=0;
5        sort(s.begin(),s.end());
6
7        for(int i=0;i<s.size()-1;i++)
8        {
9            if(s[i]=='a') continue;
10            int diff=s[i+1]-s[i];
11            ans+=diff;
12        }
13        ans+='z'-s[s.size()-1]+1;
14        return ans%26;
15    }
16};
17