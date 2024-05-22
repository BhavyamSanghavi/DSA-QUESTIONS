//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  
    int removeStudents(int a[], int n) {
    vector<int>v;
    v.push_back(a[0]);
    for(int i=1;i<n;i++)
    {
        int lb=(lower_bound(v.begin(),v.end(),a[i])-v.begin());
        if(lb==v.size())
        v.push_back(a[i]);
        else
        v[lb]=a[i];
    }
    int ans=v.size();
    return n-ans;

}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends