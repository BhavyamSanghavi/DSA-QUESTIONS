class Solution {
  public:
    vector<bool> processQueries(vector<int> &a, vector<vector<int>> &queries) {
        vector<bool>ans;
        int n=a.size();
        vector<int>l(n,0);
        vector<int>r(n,n-1);
        
        int mx=0;
        for(int i=1;i<n;i++)
        {
            if(a[i]>a[i-1])
                mx=i;
            l[i]=mx;
        }
        
        mx=n-1;
        for(int i=n-2;i>=0;i--)
        {
            if(a[i]>a[i+1])
                mx=i;
            r[i]=mx;
        }
        
        for(auto i:queries)
        {
            int s=i[0],e=i[1];
            if(r[s]>=l[e])
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        
        return ans;
    }
};