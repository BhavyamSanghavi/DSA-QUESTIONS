//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
        long long ans=0,sum=0,cur=0;
        for(int i=0;i<n;i++){
            cur+=1LL*a[i]*i;
            sum+=a[i];
        }
        for(int i=0;i<n;i++){
            cur=cur-sum+1LL*n*a[i];
            ans=max(ans,cur);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends