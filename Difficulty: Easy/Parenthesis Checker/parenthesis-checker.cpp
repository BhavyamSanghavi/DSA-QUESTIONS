//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
         stack<int> s;
        int i=0;
        int n=x.size();
        while(i<n){
            if(x[i]=='{'||x[i]=='('||x[i]=='['){
                s.push(x[i]);
            }else{
                if(s.empty()||(s.top()==-1&&(x[i]=='}'||x[i]==')'||x[i]==']'))){
                    return false;
                }else if(s.top()=='('&&x[i]==')'){
                    s.pop();
                }else if(s.top()=='{'&&x[i]=='}'){
                    s.pop();
                }else if(s.top()=='['&&x[i]==']'){
                    s.pop();
                }else{
                    return false;
                }
            }
            i++;
        }
        return s.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends