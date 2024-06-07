//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
  
bool dfs(vector<int> adj[], vector<bool>& vis, vector<bool>& recStack, vector<int>& ans, int i) {
    vis[i] = true;
    recStack[i] = true;
    
    for (auto node : adj[i]) {
        if (!vis[node]) {
            if (dfs(adj, vis, recStack, ans, node))
                return true;
        } else if (recStack[node]) {
            // Cycle detected
            return true;
        }
    }
    
    recStack[i] = false;
    ans.push_back(i);
    return false;
}
   	
    vector<int> findOrder(int n, int m, vector<vector<int>>& pre) {
    vector<int> adj[n];
    for (auto& p : pre)
        adj[p[1]].push_back(p[0]);
    
    vector<int> ans;
    vector<bool> vis(n, false);
    vector<bool> recStack(n, false);
    
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (dfs(adj, vis, recStack, ans, i)) {
                // Cycle detected, return empty vector
                return {};
            }
        }
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends