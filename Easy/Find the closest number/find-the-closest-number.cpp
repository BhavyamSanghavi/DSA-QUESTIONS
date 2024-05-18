//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        int start =0,end =n-1;
        
        while(start<=end){
            int mid = start +(end-start)/2;
            
            if(arr[mid]==k) return k;
            else if(arr[mid]<k) start = mid+1;
            else end = mid-1;
        }
        
     if(abs(arr[start]-k)<abs(arr[end]-k)){
         return arr[start];
     }else if(abs(arr[start]-k)>abs(arr[end]-k)){
         return arr[end];
     }else {
         return max(arr[start],arr[end]);
     }
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends