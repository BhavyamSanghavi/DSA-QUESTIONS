//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  void path(int row, int col, int n, vector<vector<int>> &m, string ans, vector<string>&res)
    {
        if(row<0 || col<0 || row>=n || col>=n || m[row][col]==0) return;
        if(row==n-1 && col==n-1)
        {
            res.push_back(ans);
            return;
        }
        
        m[row][col]=0;
        path(row+1,col,n,m,ans+'D',res);
        path(row-1,col,n,m,ans+'U',res);
        path(row,col-1,n,m,ans+'L',res);
        path(row,col+1,n,m,ans+'R',res);
        m[row][col]=1;
    }
    
    vector<string> findPath(vector<vector<int>> &m) {
         string ans="";
         int n=m.size();
        vector<string> res;
        path(0,0,n,m,ans,res);
        sort(res.begin(),res.end());
        return res;
    }
    
    
    
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends