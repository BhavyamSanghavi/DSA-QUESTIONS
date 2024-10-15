//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        int count=2,i=0;
        while(i<arr.size())
        {
            if(arr[i]!=i+1)
            {
                count--;
                swap(arr[i], arr[arr[i]-1]);
            }
            i++;
            if(count==0) break;
        }
        for(i=0;i<arr.size()-1;i++)
        {
            if(arr[i]>arr[i+1]) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends