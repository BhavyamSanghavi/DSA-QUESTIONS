//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   #define ll long long
    long long getCount(int n) {
        // Your code goes here
        vector<vector<ll>>mapps;
        mapps.push_back({0, 8});
        mapps.push_back({1, 2, 4});
        mapps.push_back({2, 1, 5, 3});
        mapps.push_back({3, 2, 6});
        mapps.push_back({4, 1, 5, 7});
        mapps.push_back({5, 2, 4, 6, 8});
        mapps.push_back({6, 3, 5, 9});
        mapps.push_back({7, 4, 8});
        mapps.push_back({8, 7, 0, 9, 5});
        mapps.push_back({9, 8, 6});
        
        vector<vector<ll>>dp(n,vector<ll>(10,0));
        for(ll i = 0; i < 10; i++){
            dp[0][i] = 1LL;
        }
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < 10; j++){
                for(auto k : mapps[j]){
                    dp[i][k] += dp[i-1][j];
                }
            }
        }
        ll ans = 0;
        for(int j = 0; j < 10; j++){
            ans += dp[n-1][j];
        }
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
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends