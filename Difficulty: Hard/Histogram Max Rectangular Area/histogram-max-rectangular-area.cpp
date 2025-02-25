//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &v) {
        int n=v.size();
        vector<int> lmin(n,-1);
        vector<int> rmin(n,n);
        stack<int> stack;
        stack.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!stack.empty() && v[i]<=v[stack.top()]){
                stack.pop();
            }
            if(!stack.empty()){
                rmin[i]=stack.top();
            }
            stack.push(i);
        }
        while(!stack.empty()) stack.pop();
        stack.push(0);
        for(int i=1;i<n;i++){
            while(!stack.empty() && v[i]<=v[stack.top()]){
                stack.pop();
            }
            if(!stack.empty()){
                lmin[i]=stack.top();
            }
            stack.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,(rmin[i]-lmin[i]-1)*v[i]);
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends