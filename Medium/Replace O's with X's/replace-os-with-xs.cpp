//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void bfs(vector<vector<char>> &mat,int i,int j)
    {
        int n=mat.size(),m=mat[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        
        int ar[]={1,-1,0,0};
        int ac[]={0,0,1,-1};
        while(!q.empty())
        {
            i=q.front().first, j=q.front().second; q.pop();
            mat[i][j]='A';
            
            for(int x=0;x<4;x++)
            {
                int row=ar[x]+i;
                int col=ac[x]+j;
                
                if(row>=0 && col>=0 && row<n && col<m && mat[row][col]=='O')
                {
                    q.push({row,col});
                }
            }
        }
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        
        
        for(int i=0;i<n;i++)
        {
            if(mat[i][0]=='O') bfs(mat,i,0);
            if(mat[i][m-1]=='O') bfs(mat,i,m-1);
        }
        for(int j=0;j<m;j++)
        {
            if(mat[0][j]=='O') bfs(mat,0,j);
            if(mat[n-1][j]=='O') bfs(mat,n-1,j);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]=='A') mat[i][j]='O';
                else if(mat[i][j]=='O') mat[i][j]='X';
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends