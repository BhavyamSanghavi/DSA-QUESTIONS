//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        int ans=1;
        int N=arr.size();
       unordered_set<int>s;
       for(int i=0;i<N;i++)
       {
           s.insert(arr[i]);
       }
       for(auto i:s)
       {
           if(s.find(i-1)==s.end())
           {
               int cnt=1;
               int x=i;
               while (s.find(x + 1) != s.end())
               {
                    x = x + 1;
                    cnt = cnt + 1;
                }
                ans=max(ans,cnt);
           }
       }
       return ans;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends