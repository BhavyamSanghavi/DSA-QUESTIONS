1class Solution {
2public:
3    bool canBreak(string s1, string s2)
4    {
5        for(int i=0;i<s1.size();i++)
6            if(s1[i]<s2[i]) return false;
7        return true;
8    }
9    bool checkIfCanBreak(string s1, string s2) {
10        sort(s1.begin(),s1.end());
11        sort(s2.begin(),s2.end());
12        return canBreak(s1,s2) || canBreak(s2,s1);
13    }
14};