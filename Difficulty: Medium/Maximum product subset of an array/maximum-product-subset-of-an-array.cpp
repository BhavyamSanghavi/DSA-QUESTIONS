//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        int minNeg=1e9;
        int count=0;
        int mod=(int)(1e9+7);
        bool pos=false;
        long long int ans=1;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>0){ ans=(ans*arr[i])%mod; pos=true;}
            else if(arr[i]==0) continue;
            else
            {
                ans=(ans*arr[i])%mod;
                minNeg=min(abs(arr[i]), abs(minNeg)) * -1;
                count++;
            }
        }    
        if(ans<0)
        {
            ans/=minNeg;
        }
        if(!pos && ans<0) return 0;
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends