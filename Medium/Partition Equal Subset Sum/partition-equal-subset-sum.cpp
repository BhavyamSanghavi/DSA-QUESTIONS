//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool solve(vector<int>&a, int sum, int i,vector<vector<int>>&dp)
{
    if(sum==0) return true;
    if(i>=a.size() || sum<0) return false;
    if(dp[i][sum]!=-1) return dp[i][sum];
    
    bool pick=solve(a,sum-a[i],i+1,dp);
    bool nopick=solve(a,sum,i+1,dp);
    
    return dp[i][sum]=pick || nopick;
}
bool solveTab(vector<int>&a, int sum)
{
    int n=a.size();
    vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
    for(int i=0;i<=n;i++) dp[i][0]=1;
    
    for(int i=n-1;i>=0;i--)
    {
        for(int j=1;j<=sum;j++)
        {
            bool pick=0;
            if(j-a[i]>=0)
                pick=dp[i+1][j-a[i]];
            bool nopick=dp[i+1][j];
            dp[i][j]=pick||nopick;
        }
    }
    return dp[0][sum];
}
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        // return solve(arr,sum,0,dp);
        return solveTab(arr,sum);
    }
    int equalPartition(int N, int arr[])
    {
        int sum=accumulate(arr,arr+N,0);
        if(sum%2!=0) return 0;
        vector<int>a(arr,arr+N);
        return isSubsetSum(a,sum/2);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends