//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    
    vector<int>prevSmall(vector<int>& arr)
    {
        stack<int>s;
        s.push(0);
        vector<int>ans;
        
        for(int i=0;i<arr.size();i++)
        {
            while(s.top()>=arr[i]) 
            {
                s.pop();
            }
            ans.push_back(s.top());
            s.push(arr[i]);
        }
        
        return ans;
    }
    
    vector<int>nextSmall(vector<int>& arr)
    {
        stack<int>s;
        s.push(0);
        vector<int>ans(arr.size());
        
        for(int i=arr.size()-1;i>=0;i--)
        {
            while(s.top()>=arr[i]) 
            {
                s.pop();
            }
            ans[i]=s.top();
            s.push(arr[i]);
        }
        
        return ans;
    }
    int findMaxDiff(vector<int> &arr) {
        vector<int>prev=prevSmall(arr);
        vector<int>next=nextSmall(arr);
        
        int ans=0;
        for(int i=0;i<arr.size();i++)
        {
            ans=max(ans,abs(prev[i]-next[i]));
        }
        
        return ans;
        // 0  2  4  4  7  7  2
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends