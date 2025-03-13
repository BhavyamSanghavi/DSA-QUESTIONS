//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=val.size();
        vector<int>prev(W+1),curr(W+1);
    for(int i=1;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            int nottake=prev[j];
            int take=0;
            if(j>=wt[i-1]) take=val[i-1]+prev[j-wt[i-1]];
            curr[j]=max(take,nottake);
        }
        prev=curr;
    }
    return prev[W];
        
    }
};


//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends