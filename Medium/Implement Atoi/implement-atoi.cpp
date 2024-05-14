//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        int i=0;
        int n=s.size();
        reverse(s.begin(),s.end());
        int ans=0,factor=1;
        while(i<n-1)
        {
            if(! isdigit(s[i]) && i!=n-1) return -1;
            ans+=factor*(s[i]-'0');
            factor*=10;
            i++;
        }
        if(s[n-1]=='-') return ans*(-1);
        else if(isdigit(s[n-1])) {ans+=factor*(s[i]-'0');return ans;}
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		int ans=ob.atoi(s);
		cout<<ans<<endl;
	}
}
// } Driver Code Ends