1class Solution {
2public:
3    int maxDistance(vector<int>& colors) {
4        int ans=0;
5        for(int i=0;i<colors.size()-1;i++)
6        {
7            for(int j=colors.size()-1;j>i;j--)
8            {
9                if(colors[i]!=colors[j])
10                    ans=max(ans,j-i);
11            }
12        }
13        return ans;
14    }
15};