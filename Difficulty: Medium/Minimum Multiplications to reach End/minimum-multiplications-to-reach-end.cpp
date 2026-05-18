class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        queue<int>q;
        unordered_map<int,bool>vis;
        q.push(start);
        vis[start]=1;
        unordered_map<int,int>ans;
        ans[start]=0;
        
        while(!q.empty())
        {
            int node=q.front();q.pop();
            if(node==end) return ans[node];
            
            for(int i:arr)
            {
                int val=(i*node)%1000;
                if(!vis[val]) 
                {
                    vis[val]=1;
                    q.push(val);
                    ans[val]=ans[node]+1;
                }
            }
        }
        return -1;
    }
};