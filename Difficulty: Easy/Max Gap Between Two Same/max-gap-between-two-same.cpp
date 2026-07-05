class Solution {
  public:
    int maxCharGap(string &s) {
        unordered_map<char,vector<int>>m;
        
        for(int i=0;i<s.size();i++) 
            m[s[i]].push_back(i);
        
        int ans=-1;
        for(auto i:m)
        {
            if(i.second.size()<2) continue;
            
            ans=max(ans,i.second[i.second.size()-1]-i.second[0]-1);
        }
        return ans;
    }
};