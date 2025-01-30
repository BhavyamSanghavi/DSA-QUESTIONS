//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool isSafe(vector<vector<char>>& mat, int row, int col)
  {
      int i=row,j=col;
      while(j>=0)
      {
          if(mat[i][j--]=='Q') return 0;
      }
      i=row,j=col;
      while(i>=0 && j>=0)
      {
          if(mat[i--][j--]=='Q') return 0;
      }
      i=row,j=col;
      while(j>=0 && i<mat.size())
      {
          if(mat[i++][j--]=='Q') return 0;
      }
      return 1;
  }
  void solve(vector<vector<int>>& ans, vector<int>& curr, vector<vector<char>>& mat,int row,int col, int n)
  {
      if(col==n)
      {
          ans.push_back(curr);
          return;
      }
      
      for(int i=0;i<n;i++)
      {
          if(isSafe(mat,i,col))
          {
              mat[i][col]='Q';
              curr.push_back(i+1);
              solve(ans,curr,mat,0,col+1,n);
              curr.pop_back();
              mat[i][col]='.';
          }
      }
  }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>>ans;
        vector<vector<char>>mat(n,vector<char>(n,'.'));
        vector<int>curr;
        solve(ans,curr,mat,0,0,n);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends