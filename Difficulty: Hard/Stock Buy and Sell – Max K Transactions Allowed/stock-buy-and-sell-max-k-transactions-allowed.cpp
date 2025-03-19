//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    int solve(vector<int>&prices, int k, int i, bool canBuy,vector<vector<vector<int>>>& dp)
    {
        if(i>=prices.size()) return 0;
        if(k==0) return 0;
        if(dp[k][i][canBuy]!=-1) return dp[k][i][canBuy];
        
        int profit=0;
        if(canBuy)
        {
            int buy=-prices[i]+solve(prices,k,i+1,!canBuy,dp);
            int skip=solve(prices,k,i+1,canBuy,dp);
            profit=max(buy,skip);
        }
        else
        {
            int sell=prices[i]+solve(prices,k-1,i+1,!canBuy,dp);
            int skip=solve(prices,k,i+1,canBuy,dp);
            profit=max(sell,skip);
        }
        return dp[k][i][canBuy]=profit;
    }
    
    int maxProfit(vector<int>& prices, int k) {
        vector<vector<vector<int>>>dp(k+1,vector<vector<int>>(prices.size()+1,vector<int>(2,-1)));
        return solve(prices,k,0,1,dp);
        
    }
};


//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends