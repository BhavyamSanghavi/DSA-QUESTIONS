//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

int dp[1001][1001];
    int rec(string &str, string &st2, int n, int i, int j)
    {
           if(i==n or j==n)
           return 0;
           
           if(dp[i][j]!=-1)
           return dp[i][j];
           
           if(str[i]==st2[j])
           {
                 return dp[i][j]= 1+rec(str,st2,n,i+1,j+1);
           }
           else
           {
                 int c1= rec(str,st2,n,i+1,j);
                 int c2= rec(str,st2,n,i,j+1);
                 
                 return dp[i][j]= max(c1,c2);
           }
           
    }
    int kPalindrome(string str, int n, int k)
    {
        // code here
      string st2=str;
      reverse(st2.begin(),st2.end());
      
      
      memset(dp,-1,sizeof(dp));
      int res= n-rec(str,st2,n,0,0);
      
      if(res>k)
      return 0;
      else
      return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.kPalindrome(str, n, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends