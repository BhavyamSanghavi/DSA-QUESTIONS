//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int padovanSequence(int n)
    {
       if(n<=2) return 1;
       int n_1=1, n_2=1, n_3=1, ans;
       int mod=1e9+7;
       for(int i=0;i<n-2;i++){
           ans=(n_2+n_3)%mod;
           
           n_3=n_2;
           n_2=n_1;
           n_1=ans;
       }
       return ans;
    }
    
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends