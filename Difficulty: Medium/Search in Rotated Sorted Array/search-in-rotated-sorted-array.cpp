//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(vector<int>& A, int key) {
        int l=0,h=A.size()-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(A[mid]==key)return mid;
            else if(A[l]<=A[mid])
            {
                if(A[l]<=key && A[mid]>=key)h=mid-1;
                else l=mid+1;
            }
            else
            {
                if(A[mid]<=key && A[h]>=key)l=mid+1;
                else h=mid-1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends