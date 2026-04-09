class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        unordered_set<int>s(a.begin(),a.end());
        vector<int>ans;
        for(int i:b)
            if(s.find(i)!=s.end())
            {
                if(ans.size()==0) ans.push_back(i);
                else if(ans.back()!=i) ans.push_back(i);
            }
        
        return ans;
    }
};