class Solution {
  public:
    bool wifiRange(string &s, int X) {
        int st=0;
        while(st<s.size() && s[st]!='1') st++;
        if(st==s.size() || st>X) return false;
        int last=st;
        
        for(int i=0;i<s.size();i++)
        {
            if(i-last+1>2*(X+1)) return false;
            if(s[i]=='1') last=i;
        }
        if(s.size()-last>X+1) return false;
        return true;
    }
};