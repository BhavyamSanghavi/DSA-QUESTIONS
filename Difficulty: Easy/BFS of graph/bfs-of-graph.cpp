//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();          // Number of vertices
        vector<int> ans;             // Stores BFS traversal result
        queue<int> q;                // Queue for BFS processing
        vector<bool> vis(n, false);  // Tracks visited nodes
        
        // Start BFS from node 0
        q.push(0);
        vis[0] = true;  // Mark node 0 as visited
        
        while (!q.empty()) {
            int node = q.front();  // Get the front node
            q.pop();               // Remove it from the queue
            ans.push_back(node);   // Add to the result
            
            // Explore all adjacent nodes
            for (int neighbor : adj[node]) {
                if (!vis[neighbor]) {  // If not visited
                    q.push(neighbor);  // Enqueue the neighbor
                    vis[neighbor] = true;  // Mark as visited
                }
            }
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        // Use vector of vectors instead of array of vectors.
        vector<vector<int>> adj(V);

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.bfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends