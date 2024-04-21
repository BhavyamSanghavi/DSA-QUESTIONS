//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minRow(int n, int m, vector<vector<int>> a) {
        // code here
        int ans=1e9;
        int index=n-1;
        for(int i=n-1;i>=0;i--)
        {
            int one=0;
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==1) one++;
            }
            if(ans>=one)
            {
                ans=min(ans,one);
                index=i+1;   
            }
        }
        return index;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> A(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        Solution ob;
        cout << ob.minRow(N, M, A) << "\n";
    }
}
// } Driver Code Ends