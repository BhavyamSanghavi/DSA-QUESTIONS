//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
#define ll long long 
    bool kPangram(string str, int k) {
        unordered_map<ll,ll>mp;
        ll n=str.length();
           ll sum=0;
           ll cnt=0;
            for(ll i=0;i<n;i++){
                  if(str[i]==32)continue;
                  mp[str[i]-'a']++;
                   cnt++;
            }
            if(cnt<26)return false;
             if(k>=26)return true;
            for(auto it: mp){
                  sum+=it.second-1;
            }
            ll size_=mp.size();
            ll rem=26-size_;
              if(rem<=sum && k>=rem){
                    return true;
              }
              return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends