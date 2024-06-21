//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    double value(string s){
        double a=0, b=0;
        bool flag= false;
        for(int i=0;i<(int)s.length();++i){
            if(s[i]=='/'){
                i++; flag= true;
            }
            if(flag){
                b=b*10+(s[i]-'0');
            }
            else{
                a=a*10+(s[i]-'0');
            }
        }
        return a/b;
    }
    string compareFracUtil(string x, string y){
        if(value(x)<value(y)) return y;
        else if(value(x)>value(y)) return x;
        else return "equal";
    }
    string compareFrac(string str) {
        // Code here
        int idx= -1, n= (int)str.length();
        bool flag= false;
        string x= "", y= "";
        for(int i=0;i<n;++i){
            if(str[i]==','){
                i+=2;
                flag= true;
            }
            if(flag){
                y+= str[i];
            }
            else{
                x+= str[i];
            }
        }
        return compareFracUtil(x, y);
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends