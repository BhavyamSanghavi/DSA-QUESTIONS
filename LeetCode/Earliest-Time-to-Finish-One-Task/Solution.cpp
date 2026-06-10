1class Solution {
2public:
3    int earliestTime(vector<vector<int>>& tasks) {
4        int ans=1e9;
5        for(auto i:tasks)
6            ans=min(ans,i[0]+i[1]);
7        return ans;
8    }
9};