class Solution {
  public:
    bool kSubstr(string &s, int k) {
        // code here
        unordered_map<string,int>m;
        for(int i=0;i<s.size();i+=k)
        {
            string t=s.substr(i,k);
            m[t]++;
        }
        if(m.size()>2) return false;
        vector<int>a;
        for(auto i:m)
        {
            a.push_back(i.second);
        }
        if(a.size()<=1) return true;
        return a[1]==1 || a[0]==1;
    }
};