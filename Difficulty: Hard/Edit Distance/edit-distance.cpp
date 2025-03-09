//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to compute the edit distance between two strings
    int solve(string & s1, string & s2, int i, int j,vector<vector<int>>& dp)
    {
        if(i>=s1.size()) return s2.size()-j;
        if(j>=s2.size()) return s1.size()-i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return solve(s1,s2,i+1,j+1,dp);
        
        int op1=1+solve(s1,s2,i+1,j,dp);
        int op2=1+solve(s1,s2,i,j+1,dp);
        int op3=1+solve(s1,s2,i+1,j+1,dp);
        
        return dp[i][j]=min({op1,op2,op3});
    }
    int editDistance(string& s1, string& s2) {
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return solve(s1,s2,0,0,dp);
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends