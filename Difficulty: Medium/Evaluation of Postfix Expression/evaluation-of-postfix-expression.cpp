//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        stack<string>s;
        for(string i:arr)
        {
            if(i=="+" || i=="-" || i=="*" || i=="/")
            {
                string num1=s.top(); s.pop();
                string num2=s.top(); s.pop();
                int n1=stoi(num1);
                int n2=stoi(num2);
                if(i=="+") s.push(to_string(n1+n2));
                else if(i=="-") s.push(to_string(n2-n1));
                else if(i=="*") s.push(to_string(n1*n2));
                else s.push(to_string(n2/n1));
            }
            else
            {
                s.push(i);
            }
        }
        string res=s.top(); s.pop();
        int ans=stoi(res);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends