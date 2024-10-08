//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &mat, int n, int m){
        int low=1e8, high=-1e8;
        for(int i=0;i<n;i++)
        {
            low=min(low,mat[i][0]);
            high=max(high,mat[i][m-1]);
        }
        int med=(n*m)/2;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            int cnt=0;
            for(int i=0;i<n;i++)
            {
                int ub=upper_bound(mat[i].begin(),mat[i].end(),mid)-mat[i].begin();
                cnt+=ub;
            }
            if(cnt>med) high=mid-1;
            else low=mid+1;
        }
        return low;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends