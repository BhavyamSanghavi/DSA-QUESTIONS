1class Solution {
2public:
3    vector<int>rowDir = {-1, 1, 0, 0};
4    vector<int>colDir = {0, 0, -1, 1};
5    bool isValid(vector<vector<bool>>&visited, int i, int j)
6    {
7        if (i < 0 || j < 0 || i == visited.size() || j == visited[0].size() || visited[i][j])
8            return false;
9        return true;
10    }
11    //============================================================================================================
12    bool isSafe(vector<vector<int>>&distToTheif, int safeDist) //check the validity of safenessFactor
13    {
14        int n = distToTheif.size();
15        queue<pair<int, int>>q;
16        if (distToTheif[0][0] < safeDist) return false;
17        q.push({0, 0});
18        vector<vector<bool>>visited(n, vector<bool>(n, false));
19        visited[0][0] = true;
20        while(!q.empty())
21        {
22            int currRow = q.front().first, currCol = q.front().second;
23            q.pop();
24            if (currRow == n - 1 && currCol == n - 1) return true;
25            for (int dirIdx = 0; dirIdx < 4; dirIdx++)
26            {
27                int newRow = currRow + rowDir[dirIdx];
28                int newCol = currCol + colDir[dirIdx];
29                if (isValid(visited, newRow, newCol))
30                {
31                    if (distToTheif[newRow][newCol] < safeDist) continue;
32                    visited[newRow][newCol] = true;
33                    q.push({newRow, newCol});
34                }
35            }
36        }
37        return false;
38    }
39    //===========================================================================================================
40    int maximumSafenessFactor(vector<vector<int>>& grid) 
41    {
42        int n = grid.size();
43        queue<pair<int, int>>q;
44        vector<vector<bool>>visited(n, vector<bool>(n, false));
45        vector<vector<int>>distToTheif(n, vector<int>(n, -1));
46        //========================================================================
47        //Add all the theives in current queue
48        for (int i = 0; i < n; i++)
49        {
50            for (int j = 0; j < n; j++)
51            {
52                if (grid[i][j] == 1) 
53                {
54                    visited[i][j] = true;
55                    q.push({i, j});
56                }
57            }
58        }
59        //=============================================================================
60        //BFS to fill the "DistToTheif" 2D array
61        int dist = 0;
62        while(!q.empty())
63        {
64            int size = q.size();
65            while(size--)
66            {
67                int currRow = q.front().first, currCol = q.front().second;
68                q.pop();
69                distToTheif[currRow][currCol] = dist;
70                for (int dirIdx = 0; dirIdx < 4; dirIdx++)
71                {
72                    int newRow = currRow + rowDir[dirIdx], newCol = currCol + colDir[dirIdx];
73                    if (!isValid(visited, newRow, newCol)) continue;
74                    
75                    visited[newRow][newCol] = true;
76                    q.push({newRow, newCol});
77                }
78            }
79            dist++;
80        }
81        //==================================================================================
82        //BINARY SEARCH
83        int low = 0, high = INT_MAX;
84        int ans = 0;
85        while(low <= high)
86        {
87            int mid = low + (high - low) / 2;
88            if (isSafe(distToTheif, mid))
89            {
90                ans = mid;
91                low = mid + 1;
92            }
93            else high = mid - 1;
94        }
95        //=========================================================================================
96        return ans;
97        
98    }
99};