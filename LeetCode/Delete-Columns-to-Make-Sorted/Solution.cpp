1class Solution {
2public:
3    int minDeletionSize(vector<string>& strs) {
4        int ans=0;
5        for(int j=0;j<strs[0].size();j++)
6        {
7            for(int i=1;i<strs.size();i++)
8            {
9                if(strs[i][j]<strs[i-1][j])
10                {
11                    ans++;
12                    break;
13                }
14            }
15        }
16        return ans;
17    }
18};