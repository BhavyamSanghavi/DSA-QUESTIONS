//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &m) {
        // code here
         int sr=0,er=m.size()-1,sc=0,ec=m[0].size()-1;
    vector<int>ans;
    int total=m.size()*m[0].size();
    int cnt=0;
    while(sr<=er && sc<=ec){
    for(int i=sc;i<=ec;i++)
    {
        if(cnt<total)
        {
            ans.push_back(m[sr][i]);
            cnt++;
        }
    }
    sr++;
    for(int i=sr;i<=er;i++)
    {
        if(cnt<total)
        {
            ans.push_back(m[i][ec]);
            cnt++;
        }
    }
    ec--;
    for(int i=ec;i>=sc;i--)
    {
        if(cnt<total)
        {
            ans.push_back(m[er][i]);
            cnt++;
        }
    }
    er--;
    for (int i = er; i >= sr; i--) 
    {
        if(cnt<total)
        {
            ans.push_back(m[i][sc]);
            cnt++;
        }
    }
    sc++;
}return ans;
    }
   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends