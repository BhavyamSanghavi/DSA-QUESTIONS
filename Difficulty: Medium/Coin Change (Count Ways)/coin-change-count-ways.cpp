//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>& coins, int sum, int i)
    {
        if(i>=coins.size()) return 0;
        if(sum==0) return 1;
        
        int pick=0,nopick=0;
        if(coins[i]<=sum)
        {
            pick=solve(coins,sum-coins[i],i);
            nopick=solve(coins,sum,i+1);
        }
        return pick+nopick;
    }
    int count(vector<int>& coins, int sum) {
        sort(coins.begin(),coins.end());
        return solve(coins,sum,0);
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends