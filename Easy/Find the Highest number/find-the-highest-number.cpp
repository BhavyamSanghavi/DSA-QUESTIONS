//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        int n=a.size();
        int i=0,j=a.size()-1;
        while(i<=j)
        {
            int mid=(i+j)/2;
            
            if(a[mid]>a[(mid+1)%n] && a[mid]>a[(mid-1)%n]) return a[mid];
            else if( a[mid]>a[mid-1]) i=mid+1;
            else j=mid-1;
        }
        return -1;
    }
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}


// } Driver Code Ends