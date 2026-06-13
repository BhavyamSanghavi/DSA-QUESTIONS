1class Solution {
2public:
3    string mapWordWeights(vector<string>& words, vector<int>& weights) {
4        string ans;
5        for(string s:words)
6        {
7            int cnt=0;
8            for(int i=0;i<s.size();i++)
9                cnt+=weights[s[i]-'a'];
10            ans+=('a'+(25-(cnt%26)));
11        }
12        return ans;
13    }
14};