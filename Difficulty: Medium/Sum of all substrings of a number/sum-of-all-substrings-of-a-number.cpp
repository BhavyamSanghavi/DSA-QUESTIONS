class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
        long long int ans = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            int x = s[i]-'0';
            ans += x;
            for(int j=i+1;j<n;j++){
                x = x*10 + (s[j]-'0');
                ans += x;
            }
        }
        
        return (int)(ans);
    }
};