class Solution {
  public:
  long long solve(string s, int k)
  {
  long long ans=0;
  int i=0,j=0,count=0;
  vector<int>v(26,0);
  while(j<s.size())
  {
      v[s[j]-'a']++;
      if(v[s[j]-'a']==1) count++;
      while(count>k)
      {
          v[s[i]-'a']--;
          if(v[s[i]-'a']==0) count--;
          i++;
      }
      ans+=j-i+1;
      j++;
  }
  return ans;
}
    int countSubstr(string& s, int k) {
        return solve(s,k)-solve(s,k-1);
    }
};