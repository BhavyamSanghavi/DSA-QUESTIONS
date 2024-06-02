//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
  long long solve(vector<int> &arr, int n, int target, int i)
    {
        if(i==n)
        {
            if(target==0)
            return 1;
            else
            return 0;
        }
        
        int posi = solve(arr, n, target+arr[i], i+1);
        int negi = solve(arr, n, target-arr[i], i+1);
        
        return (posi+negi)%1000000007;
    }
    long long findTargetSumWays(int n, vector<int>& A, int target) {
        if(n==1)
        {
            if(A[0] == target)
            return 1;
            else
            return 0;
        }
        int i=0;
        return solve(A, n, target, i);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin >> N;
        vector<int> arr(N);

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout << ob.findTargetSumWays(N, arr, target);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends