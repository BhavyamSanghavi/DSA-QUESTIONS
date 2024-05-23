//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  int solve(int a[], int n, int k, bool canbuy , int i,vector<vector<vector<int>>>& dp)
  {
      if(i>=n || k<=0) return 0;
      if(dp[i][canbuy][k]!=-1 ) return dp[i][canbuy][k];
      int profit=0;
      if(canbuy)
      {
          int buy=-a[i]+solve(a,n,k,!canbuy,i+1,dp);
          int skip=solve(a,n,k,canbuy,i+1,dp);
          profit+=max(buy,skip);
      }
      else
      {
          int sell=a[i]+solve(a,n,k-1,!canbuy,i+1,dp);
          int skip=solve(a,n,k,canbuy,i+1,dp);
          profit+=max(sell,skip);
      }
      return dp[i][canbuy][k]=profit;
  }
  
    int maxProfit(int K, int N, int A[]) {
        vector<vector<vector<int>>>dp(N,vector<vector<int>>(2,vector<int>(K+1,-1)));
        return solve(A,N,K,1,0,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends