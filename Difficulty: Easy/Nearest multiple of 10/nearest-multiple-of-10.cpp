//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        int n = str.size();
        int rem = str[n-1] - '0';
        int other = 10 - rem;
        if(other < rem){
            if(n == 1) return "10";
            else{
                int i = n-2;
            str[n-1] = '0';
            // case if n-2 is 9  79997
            while(i >= 0 && str[i] == '9'){
                str[i--] = '0';
            } 
            if(i == -1) return "1" + str; // if it was 997 then first element to be 1
            else str[i] += 1;  // else increment the first elemnt by 1
            }
        }else{
            // when rem is less than or equal to 5
            str[n-1] = '0';
        }
        return str;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends