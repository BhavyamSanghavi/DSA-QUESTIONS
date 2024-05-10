//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void solve(vector<int>& ans , int n)
  {
      if(n==1)
      {
          ans.push_back(n);
          return;
      }
      if(n%2==0)
      {
          ans.push_back(n);
          solve(ans,pow(n,0.5));
      }
      else
      {
          ans.push_back(n);
          solve(ans,pow(n,1.5));
      }
  }
    vector<int> jugglerSequence(int n) {
        vector<int>ans;
        solve(ans,n);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<int> ans = ob.jugglerSequence(n);
        for (int u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends