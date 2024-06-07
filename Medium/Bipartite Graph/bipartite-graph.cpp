//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

bool dfs(vector<int>adj[], bool col, vector<int>&color, int node)
{
    color[node]=col;
    
    for(auto i:adj[node])
    {
        if(color[i]==-1)
        {
            if(dfs(adj,!col,color,i)==false) return false;
        }
        else if(color[i]==col)
            return false;
    }
    return true;
}

	bool isBipartite(int V, vector<int>adj[]){
	    vector<int>color(V,-1);
	    
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)
	        {
	            if(dfs(adj,0,color,i)==false) return false;
	        }
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends