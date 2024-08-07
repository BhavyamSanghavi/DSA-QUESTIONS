//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& pre) {
	    vector<int>adj[N];
	    for(auto i:pre)
	        adj[i.first].push_back(i.second);
	    
	    vector<int>indegree(N,0);
	    for(int i=0;i<N;i++)
	    {
	        for(auto node:adj[i])
	        {
	            indegree[node]++;
	        }
	    }
	    
	    vector<int>ans;
	    queue<int>q;
	    for(int i=0;i<N;i++) if(indegree[i]==0) q.push(i);
	    
	    while(!q.empty())
	    {
	        int node=q.front(); q.pop();
	        ans.push_back(node);
	        
	        for(auto i:adj[node])
	        {
	            indegree[i]--;
	            if(indegree[i]==0) q.push(i);
	        }
	    }
	    return ans.size()==N;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends