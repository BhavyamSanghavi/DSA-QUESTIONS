//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int solve(int W, int wt[],int val[], int n, int i,vector<vector<int>>&dp)
    {
        if(i>=n || W<=0) return 0;
        if(dp[i][W]!=-1) return dp[i][W];
        int pick=0;
        if(W-wt[i]>=0)
        pick+=val[i]+solve(W-wt[i],wt,val,n,i+1,dp);
        int nopick=solve(W,wt,val,n,i+1,dp);
        
        return dp[i][W]=max(pick,nopick);
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
       return solve(W,wt,val,n,0,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends