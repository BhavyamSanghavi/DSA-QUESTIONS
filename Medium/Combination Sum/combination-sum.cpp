//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    
    void solve(vector<vector<int>>&ans, vector<int>&a,vector<int>t, int sum,int i)
    {
        if(i>=a.size())
        {
            if(sum==0)
            {
                ans.push_back(t);
                return;
            }
            return;
        }
        // if(sum<0) return;
        
        if(a[i]<=sum)
        {
        t.push_back(a[i]);
        solve(ans,a,t,sum-a[i],i);
        t.pop_back();
        }
        solve(ans,a,t,sum,i+1);
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        vector<vector<int>>ans;
        set<int>st(A.begin(),A.end());
        vector<int>arr(st.begin(),st.end());
        // sort(A.begin(),A.end());
        
        vector<int>t;
        solve(ans,arr,t,B,0);
        // sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends