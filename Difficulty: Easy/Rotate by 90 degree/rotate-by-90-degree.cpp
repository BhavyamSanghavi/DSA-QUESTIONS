//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void transpose(vector<vector<int> >& m)
    {
        for(int i=0;i<m.size();i++)
        {
            for(int j=i;j<m[0].size();j++)
            {
                swap(m[i][j],m[j][i]);
            }
        }
    }
    void rotateby90(vector<vector<int> >& matrix) 
    { 
        int n=matrix.size();
        transpose(matrix);
        for(int i=0;i<matrix[0].size();i++)
        {
            int s=0,e=matrix.size()-1;
            while(s<e)swap(matrix[s++][i],matrix[e--][i]);
        }
    } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(n, 0);
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << matrix[i][j] << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends