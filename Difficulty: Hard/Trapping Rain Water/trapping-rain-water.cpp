//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        int pre[n],post[n];
        int maxi=arr[0];
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            if(maxi<arr[i])
            {
                maxi=arr[i];
            }
            pre[i]=maxi;
        }
        maxi=arr[n-1];
        for(int i=n-1;i>=0;i--)
        {
            if(maxi<arr[i])
            {
                maxi=arr[i];
            }
            post[i]=maxi;
        }
        for(int i=0;i<n;i++)
        {
            ans+=min(pre[i],post[i])-arr[i];
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends