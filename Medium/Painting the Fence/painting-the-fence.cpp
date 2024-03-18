//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long mod=1000000007;
    // long long solve(int n,int k, vector<int>&dp)
    // {
    //     if(n==1) return (long long)k;
    //     if(n==2) return ((long long) k*k)%mod;
    //     if(dp[n]!=-1) return dp[n];
    //     long long lastsame=(solve(n-2,k,dp)*(long long)(k-1))%mod;
    //     long long lastdiff=(solve(n-1,k,dp)*(long long)(k-1))%mod;
    //     return dp[n]=(lastsame+lastdiff)%mod;
    // }
    long long solve(int n, int k)
{
    vector<int> dp(n + 1, 0);
    dp[1] = k;
    dp[2] = k * 1LL * k % mod;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = ((dp[i - 2] * 1LL * (k - 1)) % mod + (dp[i - 1] * 1LL * (k - 1)) % mod) % mod;
    }

    return dp[n];
}
    long long countWays(int n, int k){
        // vector<int>dp(n+1,-1);
        // return solve(n,k,dp);
        return solve(n,k);
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends