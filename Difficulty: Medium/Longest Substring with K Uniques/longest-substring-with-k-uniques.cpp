class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int start=0,end=0,ans=-1;
        unordered_map<char,int>m;
        while(end<s.size())
        {
            m[s[end]]++;
            if(m.size()==k)
            {
                ans=max(ans,end-start+1);
            }
            else if(m.size()>k)
            {
                while(m.size()>k)
                {
                    m[s[start]]--;
                    if(m[s[start]]==0) m.erase(s[start]);
                    start++;
                }
                ans=max(ans,end-start+1);
            }
            end++;
        }
        return ans;
    }
};