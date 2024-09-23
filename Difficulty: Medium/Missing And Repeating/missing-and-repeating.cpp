//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        vector<int>ans;
        int n=arr.size();
        int i=0;
        while(i<n)
        {
            if(arr[i]!=arr[arr[i]-1])
            swap(arr[arr[i]-1],arr[i]);
            else i++;
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<arr[i]<<" ";
        // }
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=i+1)
            {
                ans.push_back(arr[i]);
                ans.push_back(i+1);
            }
        }
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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends