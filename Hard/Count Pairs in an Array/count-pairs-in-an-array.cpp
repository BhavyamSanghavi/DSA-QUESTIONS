//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    
    int merge(vector<int>&a, int s, int mid,int e)
    {
        vector<int>t;
        int i=s,j=mid+1,k=0, inversion=0;
        
        while(i<=mid && j<=e)
        {
            if(a[i]<=a[j]) t.push_back(a[i++]);
            else
            {
                inversion+=mid-i+1;
                t.push_back(a[j++]);
            }
        }
        while(i<=mid) t.push_back(a[i++]);
        while(j<=e) t.push_back(a[j++]);
        
        int index=0;
        for(int x=s;x<=e;x++)
        {
            a[x]=t[index++];
        }
        return inversion;
    }
    
    int mergeSort(vector<int>&a, int s, int e)
    {
        int inversion=0;
        if(s<e)
        {
            int mid=(s+e)/2;
            inversion+=mergeSort(a,s,mid);
            inversion+=mergeSort(a,mid+1,e);
            inversion+=merge(a,s,mid,e);
        }
        return inversion;
    }
    
    int noOfInversions(vector<int>&a, int n)
    {
        return mergeSort(a,0,n-1);
    }
    int countPairs(int arr[] , int n ) 
    {
        vector<int>t;
        for(int i=0;i<n;i++) t.push_back(arr[i]*i);
        return noOfInversions(t,n);
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends