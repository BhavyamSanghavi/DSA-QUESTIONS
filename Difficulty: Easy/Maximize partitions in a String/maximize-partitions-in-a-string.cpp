//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        unordered_map<char,int>count;
        for(int i=0;i<s.size();i++) count[s[i]]++;
        
        unordered_map<char,int>mp;
        int cnt = 0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            count[s[i]]--;
            if(count[s[i]]==0){
                bool flag = true;
                for(auto it:mp){
                    char ch = it.first;
                    if(count[ch]>0) flag = false;
                }
                if(flag) cnt++;
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends