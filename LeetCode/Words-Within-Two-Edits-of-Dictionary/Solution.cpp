1class Solution {
2public:
3    bool canMatch(string word, string original)
4    {
5        if(word.size()!=original.size()) return false;
6        int mismatch=0;
7        for(int i=0;i<word.size();i++)
8            if(word[i]!=original[i]) mismatch++;
9        
10        return mismatch<=2;
11    }
12    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
13        vector<string>ans;
14        for(string q:queries)
15        {
16            for(string d:dictionary)
17            {
18                if(canMatch(q,d))
19                {
20                    ans.push_back(q);
21                    break;
22                }
23            }
24        }
25        return ans;
26    }
27};