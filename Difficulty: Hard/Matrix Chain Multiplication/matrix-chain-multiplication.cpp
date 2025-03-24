//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>&arr, int i, int j, vector<vector<int>>& dp)
    {
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=1e9;
        for(int k=i;k<j;k++)
        {
            int step=arr[i-1]*arr[j]*arr[k]+solve(arr,i,k,dp)+solve(arr,k+1,j,dp);
            ans=min(ans,step);
        }
        return dp[i][j]=ans;
    }
    int matrixMultiplication(vector<int> &arr) {
        int N=arr.size();
        vector<vector<int>>dp(N,vector<int>(N,-1));
        return solve(arr,1,N-1,dp);
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// } Driver Code Ends