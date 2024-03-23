//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int solve(int arr[], int n, int sum, int i,vector<vector<int>>&dp)
	{
	    if(sum==0){ return 1;}
	    if(sum<0 || i>=n) return 0;
	    if(dp[i][sum]!=-1) return dp[i][sum];
	    
	    int pick=solve(arr,n,sum-arr[i],i+1,dp);
	    int nopick=solve(arr,n,sum,i+1,dp);
	    
	    return dp[i][sum]=(pick+nopick)%1000000007;
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    sort(arr,arr+n);
	    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(arr,n,sum,0,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends