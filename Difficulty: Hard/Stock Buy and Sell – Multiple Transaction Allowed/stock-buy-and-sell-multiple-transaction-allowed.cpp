//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
  
int solve(vector<int>&prices, int i, bool buy,vector<vector<int>>& dp)
{
    if(i>=prices.size()) return 0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    int ans=0;
    if(buy)
    {
        int buynow=-prices[i]+solve(prices,i+1,!buy,dp);
        int skip=solve(prices,i+1,buy,dp);
        ans+=max(buynow,skip);
    }
    else
    {
        int sell=prices[i]+solve(prices,i+1,!buy,dp);
        int skip=solve(prices,i+1,buy,dp);
        ans+=max(sell,skip);
    }
    return dp[i][buy]=ans;
}

int solveTab(vector<int>& prices)
{
    int n=prices.size();
    vector<vector<int>>dp(n+1,vector<int>(2,0));
    for(int i=n-1;i>=0;i--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            int ans=0;
            if(buy)
            {
                int buynow=-prices[i]+dp[i+1][!buy];
                int skip=dp[i+1][buy];
                ans+=max(buynow,skip);
            }
            else
            {
                int sell=prices[i]+dp[i+1][!buy];
                int skip=dp[i+1][buy];
                ans+=max(sell,skip);
            }
            dp[i][buy]=ans;
        }
    }
    return dp[0][1];
}

    int maximumProfit( vector<int> &prices) {
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return solve(prices,0,1,dp);
        return solveTab(prices);
    }
};


//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.maximumProfit(arr);
        cout << res;

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends