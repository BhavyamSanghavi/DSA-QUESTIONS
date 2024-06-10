//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long v[], int n)
    {
        vector<int> lmin(n,-1);
        vector<int> rmin(n,n);
        stack<int> stack;
        stack.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!stack.empty() && v[i]<=v[stack.top()]){
                stack.pop();
            }
            if(!stack.empty()){
                rmin[i]=stack.top();
            }
            stack.push(i);
        }
        while(!stack.empty()) stack.pop();
        stack.push(0);
        for(int i=1;i<n;i++){
            while(!stack.empty() && v[i]<=v[stack.top()]){
                stack.pop();
            }
            if(!stack.empty()){
                lmin[i]=stack.top();
            }
            stack.push(i);
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,(rmin[i]-lmin[i]-1)*v[i]);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends