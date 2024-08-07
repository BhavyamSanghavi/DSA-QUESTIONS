//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

int solve(int n ,int m, vector<vector<int>>& mat, int i, int j,vector<vector<int>>& dp )
{
    if(i>=n ||i<0|| j>=m || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int updia=mat[i][j]+solve(n,m,mat,i-1,j+1,dp);
    int right=mat[i][j]+solve(n,m,mat,i,j+1,dp);
    int downdia=mat[i][j]+solve(n,m,mat,i+1,j+1,dp);
    
    return dp[i][j]= max({updia,right,downdia});
}
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n;i++)
            ans=max(ans,solve(n,m,M,i,0,dp));
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends