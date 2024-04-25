//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

bool isPalindrome(string& s, int start, int end)
{
    while(start<=end)
    {
        if(s[start++]!=s[end--]) return 0;
    }
    return 1;
}

int solve(string& s, int index, vector<int>&dp)
{
    if(index>=s.size()) return 0;
    if(dp[index]!=-1) return dp[index];
    int mini=1e9;
    for(int i=index;i<s.size();i++)
    {
        if(isPalindrome(s,index,i))
        {
            int ans=1+solve(s,i+1,dp);
            mini=min(ans,mini);
        }
    }
    return dp[index]=mini;
}
    int palindromicPartition(string str)
    {
        // code here
        vector<int> dp(str.size() + 1, -1);
        return solve(str,0,dp)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends