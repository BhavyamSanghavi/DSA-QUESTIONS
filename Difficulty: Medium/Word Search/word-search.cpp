//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
bool solve(vector<vector<char>>& mat, string & word, int index, int i, int j)
{
    if(index>=word.size()) return true;
    if(word[index]!=mat[i][j]) return false;
    
    bool ans=false;
    char temp=mat[i][j];
    mat[i][j]='.';
    if(j+1<mat[0].size())
        ans=ans||solve(mat,word,index+1,i,j+1);
    if(j-1>=0)
        ans=ans||solve(mat,word,index+1,i,j-1);
    if(i+1<mat.size())
        ans=ans||solve(mat,word,index+1,i+1,j);
    if(i-1>=0)
        ans=ans||solve(mat,word,index+1,i-1,j);
    
    mat[i][j]=temp;
    return ans;
}
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==word[0] && solve(mat,word,0,i,j))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends