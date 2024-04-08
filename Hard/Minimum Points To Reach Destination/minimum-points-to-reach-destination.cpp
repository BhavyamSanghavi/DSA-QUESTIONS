//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int solve(vector<vector<int>> &grid,int i,int j,int n,int m,vector<vector<int>> &dp)
    {
        if(i>=n || j>=m) return INT_MAX;
        if(i==n-1 && j==m-1) return ((grid[i][j]>=0 ? 1:((abs(grid[i][j])+1))));
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=min(solve(grid,i+1,j,n,m,dp),solve(grid,i,j+1,n,m,dp));
        return dp[i][j]=max(ans-grid[i][j],1);
    }
	int minPoints(int m, int n, vector<vector<int>> points) 
	{ 
	    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
	    
	    return solve(points,0,0,m,n,dp);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		cin >> a[i][j];

        

	    Solution ob;
	    cout << ob.minPoints(m,n,a) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends