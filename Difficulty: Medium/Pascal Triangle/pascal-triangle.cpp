//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        vector<vector<int>>t;
        vector<int>a;
        a.push_back(1);
        t.push_back(a);
        if(n==1)return t[0];
        a.clear();
        a.push_back(1);
        a.push_back(1);
        t.push_back(a);
        a.clear();
        if(n==2)return t[1];
        
        for(int i=2;i<n;i++)
        {
            a.push_back(1);
            for(int j=0;j<i-1;j++)
            {
                a.push_back((t[i-1][j]+t[i-1][j+1])%1000000007);
            }
            a.push_back(1);
            t.push_back(a);
            a.clear();
            
        }
        return t[n-1];
    }
};



//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends