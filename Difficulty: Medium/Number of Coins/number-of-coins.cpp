//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	int solverec(vector<int> &coins,int M, int V,vector<int>&dp){
        if(V==0)
        return 0;
        
        if(V<0)
        return INT_MAX;
        
        if(dp[V]!=INT_MAX)
        return dp[V];
        
        int mini=INT_MAX;
        
        for(int i=0;i<M;i++){
            
            int ans=solverec(coins,M,V-coins[i],dp);
            if(ans!=INT_MAX)
            mini=min(ans+1,mini);
        }
        
        return dp[V]=mini; 
       return mini;
    }
	int minCoins(vector<int>&coins, int M, int V) 
    { 
        vector<int> dp(V+1, INT_MAX);
        dp[0]=0;
        for(int i=1; i<=V; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(coins[j] <= i)
                {
                    int sub_res = dp[i-coins[j]];
                    if(sub_res != INT_MAX)
                    {
                        dp[i] = min(dp[i], sub_res+1);
                    }
                }
            }
        }
        return dp[V]==INT_MAX?-1:dp[V];
    } 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends