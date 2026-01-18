1class Solution {
2public:
3    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
4        sort(towers.begin(), towers.end(),
5        [](const vector<int>& a, const vector<int>& b) 
6        {
7            if (a[2] != b[2])
8                return a[2] > b[2];
9            if (a[0] != b[0])
10                return a[0] < b[0];
11            return a[1] < b[1];
12        });
13
14        for(auto i:towers)
15        {
16            int dist=abs(i[0]-center[0])+abs(i[1]-center[1]);
17            if(dist<=radius) return {i[0],i[1]};
18        }
19        return {-1,-1};
20    }
21};