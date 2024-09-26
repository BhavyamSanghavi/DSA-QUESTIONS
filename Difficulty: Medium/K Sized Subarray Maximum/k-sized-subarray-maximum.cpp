//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
        priority_queue<pair<int,int>>q;     //element,index
        int n=arr.size();
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
    cin.ignore();
    if (t == 2) {
        cout << -1 << endl;
        return 0;
    }
    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> res = obj.max_of_subarrays(k, arr);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends