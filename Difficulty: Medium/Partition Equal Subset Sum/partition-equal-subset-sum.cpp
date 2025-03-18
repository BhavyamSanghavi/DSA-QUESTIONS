//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool canPartition(vector<int>&arr, int i, int sum,vector<vector<int>>& dp)
    {
        if(sum==0) return true;
        if(i>=arr.size() || sum<0) return false;
        if(dp[i][sum]!=-1) return dp[i][sum];
        
        bool pick=canPartition(arr,i+1,sum-arr[i],dp);
        bool nopick=canPartition(arr,i+1,sum,dp);
        
        return dp[i][sum]=pick||nopick;
    }
    bool equalPartition(vector<int>& arr) {
        int sum=accumulate(arr.begin(),arr.end(),0);
        if(sum%2==1) return false;
        vector<vector<int>>dp(arr.size()+1,vector<int>(sum+1,-1));
        return canPartition(arr,0,sum/2,dp);
        
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

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends