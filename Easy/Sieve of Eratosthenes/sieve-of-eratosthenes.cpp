//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int n)
    {
        vector<int> ans;
        vector<int> mark(n+1,0);
        
        for(int i=2; i<=n; i++){
            if(mark[i] == 0){
                for(int j=i*i; j<=n; j+=i){
                    mark[j] = 1;
                }
            }
        }
        
        for(int i=2; i<=n; i++){
            if(mark[i] == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends