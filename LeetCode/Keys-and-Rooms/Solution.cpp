1class Solution {
2public:
3    bool canVisitAllRooms(vector<vector<int>>& rooms) {
4        int n=rooms.size();
5        vector<bool>vis(n,false);
6        queue<int>q;
7
8        for(int i=0;i<rooms[0].size();i++)
9            q.push(rooms[0][i]);
10        vis[0]=true;
11
12        while(!q.empty())
13        {
14            int id=q.front(); q.pop();
15            vis[id]=true;
16
17            vector<int>keys=rooms[id];
18            for(int i:keys)
19            {
20                if(!vis[i])
21                {
22                    q.push(i);
23                }
24            }
25        }
26        for(int i=0;i<vis.size();i++)
27            if(vis[i]==false) return false;
28        
29        return true;
30    }
31};