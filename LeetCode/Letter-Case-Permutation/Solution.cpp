1class Solution {
2public:
3    vector<string>ans;
4    void solve(string s, int i)
5    {
6        if(i>=s.size()) 
7        {
8            ans.push_back(s);
9            return;
10        }
11        if(s[i]>='0' && s[i]<='9') return solve(s,i+1);
12
13        solve(s,i+1); //skip keep it lower
14        s[i]=toupper(s[i]);
15        solve(s,i+1);
16        s[i]=tolower(s[i]);
17    }
18    vector<string> letterCasePermutation(string s) {
19        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
20        solve(s,0);
21        return ans;
22    }
23};