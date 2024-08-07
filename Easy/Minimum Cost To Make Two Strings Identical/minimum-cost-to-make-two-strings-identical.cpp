//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
  
  int LCS(string &x,string &y,int n,int m,vector<vector<int>>&dp){
        if(n==0 || m==0){
            return 0;
        }
        
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        
        if(x[n-1] == y[m-1]){
            return dp[n][m] = 1 + LCS(x,y,n-1,m-1,dp);
        }
        
        int len1 = LCS(x,y,n-1,m,dp);
        int len2 = LCS(x,y,n,m-1,dp);
        return dp[n][m] = max(len1,len2);
    }
    int findMinCost(string x, string y, int costX, int costY) {
        int n = x.size(),m = y.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int lcs = LCS(x,y,n,m,dp);
        return (n - lcs) * costX + (m - lcs) * costY;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;

        int costX, costY;
        cin >> costX >> costY;

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends