//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        priority_queue<pair<int,int>>q;     //element,index
        vector<int>ans;
        int n=arr.size();
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
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends