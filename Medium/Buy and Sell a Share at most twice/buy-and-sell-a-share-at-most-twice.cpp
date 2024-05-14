//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        //User function Template for C++
        
int solve(vector<int>& prices, int i, int t, bool canbuy,vector<vector<vector<int>>>& dp)
{
    if(i>=prices.size() || t<=0) return 0;
    if(dp[i][canbuy][t]!=-1) return dp[i][canbuy][t];
    int ans=0;
    if(canbuy)
    {
        int buy=-prices[i]+solve(prices,i+1,t,!canbuy,dp);
        int skip=solve(prices,i+1,t,canbuy,dp);
        ans+=max(buy,skip);
    }
    else
    {
        int sell=prices[i]+solve(prices,i+1,t-1,!canbuy,dp);
        int skip=solve(prices,i+1,t,canbuy,dp);
        ans+=max(sell,skip);
    }
    return dp[i][canbuy][t]=ans;
}

int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
    return solve(prices,0,2,1,dp);
}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends