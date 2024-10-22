//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
         unordered_map<int, int> diffMap;

        // Initialize counters for x and y
        int x_count = 0, y_count = 0;
        
        // This is to handle the case where we have equal occurrences from the start (i.e. difference = 0)
        diffMap[0] = 1; 

        int result = 0;

        for (int num : arr) {
            // Update counts of x and y based on the current number in the array
            if (num == x) x_count++;
            if (num == y) y_count++;

            // Calculate the difference between the counts of x and y
            int diff = x_count - y_count;

            // If this difference has been seen before, add to result the count of that difference
            result += diffMap[diff];

            // Increment the occurrence of this difference in the map
            diffMap[diff]++;
        }

        return result;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int x = stoi(ks);
        string ks1;
        getline(cin, ks1);
        int y = stoi(ks1);
        Solution ob;
        int ans = ob.sameOccurrence(arr, x, y);
        cout << ans << "\n";
        // cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends