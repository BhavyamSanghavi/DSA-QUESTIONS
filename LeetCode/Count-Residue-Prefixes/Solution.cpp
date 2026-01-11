1class Solution {
2public:
3    int residuePrefixes(string s) {
4        unordered_set<char>st;
5        int ans=0;
6        for(int i=0;i<s.size();i++)
7        {
8            st.insert(s[i]);
9            if(st.size()==(i+1)%3)
10                ans++;
11        }
12        return ans;
13    }
14};