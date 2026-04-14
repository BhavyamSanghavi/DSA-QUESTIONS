class Solution {
  public:
    string URLify(string &s) {
        string ans="";
        for(char i:s)
        {
            if(i==' ') ans+="%20";
            else ans+=i;
        }
        return ans;
    }
};