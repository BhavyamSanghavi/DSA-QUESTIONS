//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& a, string& b) {
        // Your code here
        if(a.size()!=b.size())return false;
        map<char,int>m;
        for(int i=0;i<a.size();i++)
        {
            m[a[i]]++;
        }
        for(int i=0;i<b.size();i++)
        {
            m[b[i]]--;
        }
        for(auto i:m)
        {
            if(i.second!=0)return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends