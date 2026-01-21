class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        stack<pair<int,int>>s;
        vector<int>ans;
        for(int i:arr)
        {
            int span=1;
            while(!s.empty() && s.top().first<=i)
            {
                span+=s.top().second;
                s.pop();
            }
            s.push({i,span});
            ans.push_back(span);
        }
        return ans;
    }
};