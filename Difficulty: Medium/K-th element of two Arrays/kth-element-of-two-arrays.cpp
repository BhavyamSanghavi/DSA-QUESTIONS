//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(vector<int>& arr1, vector<int>& arr2, int k) {
        int n=arr1.size(), m=arr2.size();
        int i=0,j=0;
        int val1=0, val2=0;
        for(int cnt=0;cnt<=k;cnt++)
        {
            val2=val1;
            if(i!=n && j!=m)
            {
                if(arr1[i]<=arr2[j]) val1=arr1[i++];
                else val1=arr2[j++];
            }
            else if(i<n) val1=arr1[i++];
            else if(j<m) val1=arr2[j++];
        }
        return val2;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends