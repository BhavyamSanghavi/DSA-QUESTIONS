//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
    stack<int> st;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            if (!st.empty() && s[st.top()] == '(') {
                st.pop();
            } else {
                st.push(i);
            }
        }
    }

    int maxi = 0;
    int length = s.length();

    while (!st.empty()) {
       
        maxi = max(maxi, length - st.top() - 1);
        length = st.top();
        st.pop();
    }
     return max(length, maxi);
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends