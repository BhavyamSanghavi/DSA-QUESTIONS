class Solution {
  public:
    bool countFreq(vector<int>& map, int k)
    {
        int cnt=0;
        for(int i=0;i<map.size();i++)
        {
            if(map[i]>0)
                cnt++;
        }
        return cnt==k;
    }
    int substrCount(string &s, int k) {
        // code here
        vector<int>map(26,0);
        int i=0,j=0,ans=0;
        for(i=0;i<k;i++)
            map[s[i]-'a']++;
        while(i<s.size())
        {
            if(countFreq(map,k-1))
                ans++;
            
            map[s[i++]-'a']++;
            map[s[j++]-'a']--;
        }
        if(countFreq(map,k-1))
            ans++;
        return ans;
    }
};