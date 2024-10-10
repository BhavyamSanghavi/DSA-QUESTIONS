//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        unordered_map<int,vector<int>>m;
        for(int i=0;i<arr.size();i++)
        {
            m[arr[i]].push_back(i);
        }
        
        int ans=0;
        for(auto i:m)
        {
            vector<int>t=i.second;
            sort(t.begin(), t.end());
            ans=max(ans,t[t.size()-1]-t[0]);
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
        getline(cin, input);

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends