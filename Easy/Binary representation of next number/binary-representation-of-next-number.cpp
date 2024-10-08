//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        int n = s.size();
        int i = n - 1;

        // Step 2: Loop for carry propagation
        while (i >= 0 && s[i] == '1') {
            s[i] = '0';
            i--;
        }

        // Step 3: Handle full carry propagation
        if (i < 0) {
            s = '1' + s;  // Prepend '1' to handle full carry
        }
        // Step 4: Handle partial carry propagation
        else {
            s[i] = '1';  // Change '0' to '1' to complete the addition
        }

        // Step 5: Trim leading zeros
        return s.substr(s.find('1'));  // Return the substring from the first '1'
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends