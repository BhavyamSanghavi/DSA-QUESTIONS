//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


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

  
    int stockBuyAndSell(int n, vector<int> &prices) {
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(prices,0,1,dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends