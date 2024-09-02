//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	
	int solve(string s1, string s2,int i, int j,vector<vector<int>>& dp)
	{
	    if(i>=s1.size()) return s2.size()-j;
	    if(j>=s2.size()) return s1.size()-i;
	    if(dp[i][j]!=-1) return dp[i][j];
	    if(s1[i]==s2[j])
	    {
	        return dp[i][j]=solve(s1,s2,i+1,j+1,dp);
	    }
	    int add=1+solve(s1,s2,i,j+1,dp);
	    int del=1+solve(s1,s2,i+1,j,dp);
	    return dp[i][j]= min(add,del);
	}
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    vector<vector<int>>dp(str1.size()+1, vector<int>(str2.size()+1,-1));
	    return solve(str1,str2, 0,0,dp);
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends