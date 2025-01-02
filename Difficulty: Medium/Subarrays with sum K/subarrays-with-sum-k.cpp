//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
         int n=arr.size();
        vector<int>pf(n);
        pf[0]=arr[0];
        for(int i=1;i<n;i++){
            pf[i]=arr[i]+pf[i-1];
        }
        unordered_map<int,vector<int>>m;
        for(int i=0;i<n;i++){
            m[pf[i]].push_back(i);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(pf[i]==k) cnt++;
            if(m.count(pf[i]-k)!=0){
                for(int it:m[pf[i]-k]){
                    if(it<i) cnt++;
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.countSubarrays(arr, k);
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends