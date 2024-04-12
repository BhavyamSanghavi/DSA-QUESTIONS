//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        int ans=INT_MAX;
        int xin=-1,yin=-1;
        for(int i=0;i<n;i++)
        {
            if(a[i]==x) 
            {
                xin=i;
            }
            else if(a[i]==y)
            {
                yin=i;
            }
            if(xin!=-1 && yin!=-1)
            {
                ans=min(ans,abs(xin-yin));
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends