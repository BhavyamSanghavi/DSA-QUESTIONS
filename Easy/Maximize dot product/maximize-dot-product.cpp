//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	public:
	int solveMem(int n , int m , int A[] , int B[], vector<vector<int>>&dp){
    if(n<0||m<0)
     return 0;
    if(dp[n][m]!=-1)
     return dp[n][m];
    int include = A[n]*B[m] + solveMem(n-1 , m-1, A,B,dp);
    int exclude = (n==m)?0:solveMem(n-1,m,A,B,dp);
  dp[n][m]= max(include , exclude);
  return dp[n][m];
}
	int maxDotProduct(int n, int m, int A[], int B[]) 
	{ 
	     vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
        
        for(int i=1; i<=m; i++){
            for(int j=i; j<=n; j++){
                dp[i][j]=max(A[j-1]*B[i-1]+dp[i-1][j-1], dp[i][j-1]);
            }
        }
        return dp[m][n];
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends