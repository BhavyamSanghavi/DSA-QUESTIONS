class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        unordered_map<int,int>m;
        for(int i:arr) m[i]++;
        
        vector<int>ans(arr.size());
        stack<pair<int,int>>s;
        for(int i=arr.size()-1;i>=0;i--)
        {
            int freq=m[arr[i]];
            while(!s.empty() && s.top().second<=freq) s.pop();
            if(s.empty()) ans[i]=-1;
            else ans[i]=s.top().first;
            s.push({arr[i],freq});
        }
        return ans;
    }
};
