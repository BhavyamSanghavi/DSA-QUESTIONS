class Solution {
public:
    unordered_map<int,vector<pair<int,int>>> adj;
    bool isValid(int n,int s,int t,int limit,int mid){
        vector<int>result(n,INT_MAX);
        queue<pair<int,int>>q;
        q.push({s,0});//node,used k
        result[s]=0;
        while(!q.empty()){
            auto [u,k] = q.front();q.pop();
            for(auto [node,w]:adj[u]){
               int val=w>mid?1:0;
               if(result[node]>(val+k)){
                result[node]=val+k;
                q.push({node,k+val});
               }
            }
        }
        if(result[t]==INT_MAX) return false;
        return result[t]<=limit;
    }
    int minimumThreshold(int n, vector<vector<int>>& edges, int s, int t, int k) {
        for(auto&e:edges){
            int u=e[0],v=e[1],w=e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        int l=0,r=1e9;int ans=-1;
        while(l<=r){
            int mid= l+(r-l)/2;
            if(isValid(n,s,t,k,mid)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};