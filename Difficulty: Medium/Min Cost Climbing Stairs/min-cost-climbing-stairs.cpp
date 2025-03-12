//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
    int solve(vector<int>& cost, int i,vector<int>& dp)
    {
        if(i>=cost.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int oneStep=cost[i]+solve(cost,i+1,dp);
        int twoStep=cost[i]+solve(cost,i+2,dp);
        
        return dp[i]=min(oneStep,twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1,-1);
        return min(solve(cost,0,dp),solve(cost,1,dp));
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends