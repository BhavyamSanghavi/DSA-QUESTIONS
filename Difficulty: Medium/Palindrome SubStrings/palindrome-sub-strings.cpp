//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int helper(string& s, int left, int right) {
        int res = 0;
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            res++;
            left--, right++;
        }
        return res;
    }
    
    int countPS(string &s) {
        int ans = 0;
        int n = s.size();
        
        for(int i = 0; i < n - 1; i++) {
            ans += (helper(s, i - 1, i + 1)) + 
                   (s[i] == s[i + 1] ? 1 + helper(s, i - 1, i + 2) : 0);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends