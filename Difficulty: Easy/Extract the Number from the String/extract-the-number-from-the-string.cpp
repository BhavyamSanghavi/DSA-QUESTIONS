//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:

         long long ExtractNumber(string sentence) {
        int n=sentence.length();
        int i=0,flag=0,flagx=0;
        long long int x=0,ans=0;
        long long int final=INT_MIN;
        int last=0;
        for(int i=0;i<n;i++){
            if((sentence[i]-'0')<10){
                if(i==n-1){
                    last=1;
                }
            if(sentence[i]==' ' && flag==0){
                continue;
            }
            if(sentence[i]==' ' && flag==1 && flagx==0){
                final=max(x,final);
                x=0;
                flag=0;
                continue;
            }
            if(sentence[i]==' ' && flag==1 && flagx==1){
                x=0;
                flag=0;
                flagx=0;
                continue;
            }
            if((sentence[i]-'0')==9){
                flagx=1;
            }
            x=x*10+(sentence[i]-'0');
            flag=1;
            if(last==1 && flagx==0){
                final=max(x,final);
            }
            
        }
    }
        if(final==INT_MIN){
            return -1;
        }else{
       return final;
        }
    
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends