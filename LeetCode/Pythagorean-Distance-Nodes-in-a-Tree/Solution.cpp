1class Solution {
2public:
3    void getDistance(vector<vector<int>>& adj, vector<bool>& vis, int node, int len, vector<int>& distance)
4    {
5        distance[node]=0;
6        vis[node]=1;
7        queue<int>q;
8        q.push(node);
9
10        while(!q.empty())
11        {
12            int curr=q.front(); q.pop();
13
14            for(int nbr:adj[curr])
15            {
16                if(!vis[nbr])
17                {
18                    vis[nbr]=1;
19                    distance[nbr]=distance[curr]+1;
20                    q.push(nbr);
21                }
22            }
23        }
24
25    }
26    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
27        vector<vector<int>>adj(n);
28        for(auto i:edges)
29        {
30            adj[i[0]].push_back(i[1]);
31            adj[i[1]].push_back(i[0]);
32        }
33
34        vector<int>dx(n),dy(n),dz(n);
35        vector<bool>vx(n,0),vy(n,0),vz(n,0);
36        getDistance(adj,vx,x,0,dx);
37        getDistance(adj,vy,y,0,dy);
38        getDistance(adj,vz,z,0,dz);
39
40        int ans=0;
41        for(int i=0;i<dx.size();i++)
42        {
43            int d1=dx[i],d2=dy[i],d3=dz[i];
44            vector<int>t={d1,d2,d3};
45            sort(t.begin(),t.end());
46            if (1LL*t[0]*t[0] + 1LL*t[1]*t[1] == 1LL*t[2]*t[2])
47    ans++;
48
49        }
50        return ans;
51    }
52};