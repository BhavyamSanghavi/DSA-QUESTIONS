//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    // long long solve(vector<long long>&prices, int n, int fee, bool canbuy, int i,vector<vector<long long>>&dp)
    // {
    //     if(i>=n) return 0;
    //     if(dp[i][canbuy]!=-1) return dp[i][canbuy];
    //     long long profit=0;
    //     if(canbuy)
    //     {
    //         int buy=-prices[i]+solve(prices,n,fee,!canbuy,i+1,dp);
    //         int skip=solve(prices,n,fee,canbuy,i+1,dp);
    //         profit+=max(skip,buy);
    //     }
    //     else
    //     {
    //         int sell=prices[i]-fee+solve(prices,n,fee,!canbuy,i+1,dp);
    //         int skip=solve(prices,n,fee,canbuy,i+1,dp);
    //         profit+=max(skip,sell);
    //     }
    //     return dp[i][canbuy]=profit;
    // }
    
    
    
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
         long long profit=0,buy=INT_MIN;
        for(int i=0;i<n;i++)
        {
            long long price=prices[i];
            buy=max(buy,profit-price-fee);
            profit=max(profit,buy+price);
        }
        return profit ;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        int fee; cin>>fee;
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n, fee)<<"\n";
    }
    return 0;
}
// } Driver Code Ends