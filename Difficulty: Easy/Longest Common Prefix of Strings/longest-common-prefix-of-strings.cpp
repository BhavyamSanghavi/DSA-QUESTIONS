//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        int N=arr.size();
        if (N == 0) return ""; // Handle the case of an empty array.
    if (N == 1) return arr[0];

    int minLen = INT_MAX; // Find the minimum length of the strings in the array.
    for (int i = 0; i < N; i++) {
        minLen = min(minLen, static_cast<int>(arr[i].size()));
    }

    string ans = "";
    for (int index = 0; index < minLen; index++) {
        char c = arr[0][index];
        for (int j = 1; j < N; j++) {
            if (arr[j][index] != c) {
                if(ans.size()==0)return "-1";
                return ans; // Return the common prefix found so far.
            }
        }
        ans.push_back(c);
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
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends