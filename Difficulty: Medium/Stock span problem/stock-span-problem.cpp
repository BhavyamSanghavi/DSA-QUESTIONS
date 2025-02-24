//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        stack<pair<int,int>>s;      // arr[i], no. of elements smaller than it
        vector<int>ans;
        s.push({1e9,0});
        
        for(int i=0;i<arr.size();i++)
        {
            int freq=1;
            int curr=arr[i];
            while(s.top().first<=curr)
            {
                 freq+=s.top().second;
                 s.pop();
            }
            s.push({curr,freq});
            ans.push_back(freq);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.calculateSpan(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends