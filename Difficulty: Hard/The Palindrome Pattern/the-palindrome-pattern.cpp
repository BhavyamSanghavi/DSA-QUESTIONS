//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    bool isPalindromeRow(vector<int>& row)
    {
        int i=0,j=row.size()-1;
        while(i<j)
        {
            if(row[i++]!=row[j--]) return false;
        }
        return true;
    }
    bool isPalindromeCol(vector<vector<int>> &arr, int col)
    {
        int i=0,j=arr.size()-1;
        while(i<j)
        {
            if(arr[i++][col]!=arr[j--][col]) return false;
        }
        return true;
    }
    string pattern(vector<vector<int>> &arr) {
        for(int v=0;v<arr.size();v++)
        {
            if(isPalindromeRow(arr[v]))
            {
                string ans=to_string(v);
                ans+=" R";
                return ans;
            }
        }
        
        for(int v=0;v<arr[0].size();v++)
        {
            if(isPalindromeCol(arr,v))
            {
                string ans=to_string(v);
                ans+=" C";
                return ans;
            }
        }
        
        return "-1";
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends