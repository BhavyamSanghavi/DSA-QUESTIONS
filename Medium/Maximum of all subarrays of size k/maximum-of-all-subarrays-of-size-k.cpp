//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        priority_queue<pair<int,int>>q;     //element,index
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            q.push({arr[i],i});
        }
        
        for(int i=0;i<n-k;i++)
        {
            ans.push_back(q.top().first);
            while(!q.empty() && i>=q.top().second) q.pop();
            q.push({arr[i+k],i+k});
        }
        ans.push_back(q.top().first);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends