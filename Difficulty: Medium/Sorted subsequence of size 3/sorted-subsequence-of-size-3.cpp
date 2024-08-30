//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

bool isSubSequence(vector<int> &v1, vector<int> &v2) {
    int m = v2.size();
    int n = v1.size();
    int j = 0; // For index of v2

    // Traverse v1 and v2
    for (int i = 0; i < n && j < m; i++) {
        if (v1[i] == v2[j]) {
            j++;
        }
    }
    return (j == m);
}


// } Driver Code Ends
// Function to find three numbers in the given array
// such that arr[smaller[i]] < arr[i] < arr[greater[i]]

class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        vector<vector<int>>small(arr.size());
        stack<int>s;
        s.push(0);
        for(int i=0;i<arr.size();i++)
        {
            while(s.top()>=arr[i]) 
            {
                s.pop();
            }
            if(s.top()!=0)
                small[i].push_back(s.top());
            
            s.push(arr[i]);
        }
        
        // for(auto i:small)
        // {
        //     for(auto j:i) cout<<j<<"   ";
        //     cout<<endl;
        // }
        
        while(s.size()!=0) s.pop();
        s.push(1e9);
        vector<int>ans;
        for(int i=arr.size()-1;i>=0;i--)
        {
            while(s.top()<=arr[i]) 
            {
                s.pop();
            }
            if(s.top()!=1e9)
                small[i].push_back(s.top());
            if(small[i].size()==2)
            {
                ans.push_back(small[i][0]);
                ans.push_back(arr[i]);
                ans.push_back(small[i][1]);
                
                // for(auto i:ans) cout<<i<<"   "; cout<<endl;
                return ans;
            }
            
            s.push(arr[i]);
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

// Driver program to test above function
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution obj;
        auto res = obj.find3Numbers(arr);
        // wrong format output
        if (!res.empty() and res.size() != 3) {
            cout << -1 << "\n";
        }

        if (res.empty()) {
            cout << 0 << "\n";
        } else if ((res[0] < res[1] and res[1] < res[2]) and isSubSequence(arr, res)) {
            cout << 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
// } Driver Code Ends