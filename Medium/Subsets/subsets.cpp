//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     vector<vector<int>>ans;
    void solve(vector<int>a , vector<int>op){
        if(a.size() == 0){
            ans.push_back(op);
            return ;
        }
        vector<int>op1 = op;
        vector<int>op2 = op;
        op2.push_back(a[0]);
        a.erase(a.begin() + 0);
        solve(a , op1);
        solve(a , op2);
    }
  
    vector<vector<int> > subsets(vector<int>& a) {
        vector<int>op;
        solve(a , op);
        sort(ans.begin() , ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n;

        vector<int> array;
        for (int i = 0; i < n; i++) {
            cin >> x;
            array.push_back(x);
        }

        Solution ob;
        vector<vector<int> > res = ob.subsets(array);

        // Print result
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++)
                cout << res[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}
// } Driver Code Ends