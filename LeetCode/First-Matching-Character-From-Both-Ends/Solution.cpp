1class Solution {
2public:
3    int firstMatchingIndex(string s) {
4        for(int i=0;i<s.size();i++)
5            if(s[i]==s[s.size()-i-1]) return i;
6        return -1;
7    }
8};