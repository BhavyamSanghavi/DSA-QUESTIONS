//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int myAtoi(char *s) {
        int i=0;
        while(s[i]==' ') i++;
        bool sign = false;
        if(s[i]=='-') sign=true, i++;
        
        int num=0;
        while(s[i]>='0' && s[i]<='9')
        {
            int d=s[i]-'0';
            if(num>INT_MAX/10 || (num == INT_MAX/10 && d>INT_MAX%10))
                return sign ? INT_MIN : INT_MAX;
            
            num=num*10+d;
            i++;
        }
            
        
        return sign ? -num : num;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends