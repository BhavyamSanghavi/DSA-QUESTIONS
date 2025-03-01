//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
  bool isnum(char c)
  {
      if(c>='1' && c<='9') return true;
      return false;
  }
    string decodedString(string &s) {
         int n = s.size();
        
        stack<string> st;
        int num = 0;
        
        int i = n-1;
        
        while(i>=0){
            if(s[i]>='0' && s[i]<='9'){
                string t;
                while(i>=0 && s[i]>='0' && s[i]<='9'){
                    t.push_back(s[i]);
                    i--;
                }
                reverse(t.begin(),t.end());
                
                num = stoi(t);
                string p="";
                
                st.pop();
                while(st.top()!="]"){
                    p+=st.top();
                    st.pop();
                }
                st.pop();
                
                string pp="";
                for(int i=0;i<num;i++){
                    pp = pp + p;
                }
                
                st.push(pp);
                   
            }
            else{
                string t;
                t.push_back(s[i]);
                
                st.push(t);
                i--;
                
            }

        }
        
        string ans = "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends