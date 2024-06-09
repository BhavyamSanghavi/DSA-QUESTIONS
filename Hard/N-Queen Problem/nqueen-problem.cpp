//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

bool isSafe(vector<vector<int >>chess,int row,int col,int n){
        //vertically up
        for(int i=row-1;i>=0;i--){
            if(chess[i][col]==1){
                return false;
            }
        }
        //diagonally left
        for(int i=row-1,j=col-1;i>=0 && j>=0 ;i--,j--){
            if(chess[i][j]==1){
                return false;
            }
        }
        //diagonally right
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(chess[i][j]==1){
                return false;
            }
        }
        return true;
    }
    void Findans(vector<vector<int >>chess,int n,vector<vector<int >>&ans){
        vector<int>temp;
          for(int i=0;i<n;i++){
              for(int j=0;j<n;j++){
                                if(chess[i][j]==1){
                  temp.push_back(j+1);
              }
              }
          }
          ans.push_back(temp);
    }
    
void solve(int row,vector<vector<int >>chess,int n,vector<vector<int >>&ans){
    //basecase
    if(row==n){
       Findans(chess,n,ans);
       return;
    }
    //recursive call
    for(int i=0;i<n;i++){
        if(isSafe(chess,row,i,n)){
            chess[row][i]=1;
            solve(row+1,chess,n,ans);
            //backtracking
            chess[row][i]=0;
        }
    }
}
public:
    vector<vector<int>> nQueen(int n) {
     vector<vector<int >>chess(n,vector<int>(n,0));
     vector<vector<int>>ans;
     solve(0,chess,n,ans);
     return ans ;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends