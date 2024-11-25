//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        int maxi=-1e9, mini=1e9;
        int sum=0,maxsum=0,minsum=0;
        for(auto i:arr)
        {
            maxi=max(maxi,i+maxsum);
            mini=min(mini,i+minsum);
            sum+=i;
            maxsum+=i;
            minsum+=i;
            
            if(minsum>0) minsum=0;
            if(maxsum<0) maxsum=0;
        }
        if(maxi<0) return maxi;
        return max(maxi,sum-mini);
        
        
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
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends