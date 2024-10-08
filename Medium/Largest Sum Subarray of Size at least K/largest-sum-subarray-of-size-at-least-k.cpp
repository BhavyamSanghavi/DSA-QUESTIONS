//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        long long int sum = 0;
        for(long long int i = 0; i < k; i++){
            sum += a[i];
        }
        long long int maxsum = sum;
        long long int p = maxsum; 
        for(long long int  i = k; i < n; i++){
            sum = sum + a[i] - a[i - k];
            p = max(p + a[i], sum);
            maxsum = max(maxsum, p);
        }
        return maxsum;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends