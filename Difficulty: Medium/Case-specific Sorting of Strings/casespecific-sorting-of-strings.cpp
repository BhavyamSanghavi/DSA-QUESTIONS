class Solution {
  public:
    int getlast(string &s)
    {
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]>='A' && s[i]<='Z')
                return i;
        }
        return -1;
    }
    string caseSort(string& s) {
         int n=s.size();
        string ans="";
        int a[26]={0},b[26]={0},k[n]={0};
        for(int i=0;i<n;i++)
        {
            if(s[i]<='Z'){
                a[s[i]-'A']++;
                k[i]+=1;
            }
            else
            {
                b[s[i]-'a']++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(k[i])
            {
                for(int j=0;j<26;j++){
                 if(a[j]){
                     ans+=j+'A';
                     a[j]--;
                     break;
                 }
                }
            }
            else
            {
                for(int j=0;j<26;j++){
                 if(b[j]){
                     ans+=j+'a';
                     b[j]--;
                     break;
                 }
                }
            }
        }
        return ans;
    }
};