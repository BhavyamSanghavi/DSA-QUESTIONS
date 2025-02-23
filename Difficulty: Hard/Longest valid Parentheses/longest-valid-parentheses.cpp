//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxLength(string& s) {
        stack<pair<char,int>> stt;
        vector<pair<int,int>> ans;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                stt.push({'(',i});
            }
            else
            {
                if(stt.size()>0)
                {
                    int ind=stt.top().second;
                    stt.pop();
                    ans.push_back({ind,i});
                }
            }
        }
        if(ans.size()==0)return 0;
        sort(ans.begin(),ans.end());
        int st=ans[0].first;
        int ed=ans[0].second;
        int ct=ed-st+1;
        for(int i=1;i<ans.size();i++)
        {
            int ind1=ans[i].first;
            int ind2=ans[i].second;
            if(ind1-ed==1)
            {
                ed=ind2;
                ct=max(ct,ed-st+1);
            }
            else if(ind1-ed>1)
            {
                st=ind1;
                ed=ind2;
                ct=max(ct,ed-st+1);
            }
            else if(st>ind1 && ed>ind2)
            {
                
            }
        }
        return ct;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends