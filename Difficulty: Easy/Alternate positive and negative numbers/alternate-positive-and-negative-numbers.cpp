//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        int n = arr.size();
        // create  vector for store positive and negative number
        vector<int>pos, neg;
        
        for(int i = 0; i<n; i++)
        {
            if(arr[i] >= 0)                        // if number >= 0 then push in pos array
                pos.push_back(arr[i]);
            else
                neg.push_back(arr[i]);
        }

        // re fill number in arr alternatively positive and negative
        int i =  0, j=0, index = 0;
        while(i < pos.size() && j<neg.size())
        {
            arr[index++] = pos[i++];
            arr[index++] = neg[j++];
        }
        while(i<pos.size())
            arr[index++] = pos[i++];
            
        while(j < neg.size())
            arr[index++] = neg[j++];
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends