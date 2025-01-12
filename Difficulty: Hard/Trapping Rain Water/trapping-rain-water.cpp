//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n=arr.size();
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
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends