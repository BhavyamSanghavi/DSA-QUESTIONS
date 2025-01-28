//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  void solve(unordered_set<string>& ans, string & s,  int index)
  {
      if(index>=s.size())
      {
          ans.insert(s);
          return;
      }
      for(int i=index;i<s.size();i++)
      {
          swap(s[i],s[index]);
          solve(ans,s,index+1);
          swap(s[i],s[index]);
      }
  }
  
    vector<string> findPermutation(string &s) {
        unordered_set<string>ans;
        solve(ans,s,0);
        vector<string>res(ans.begin(), ans.end());
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends