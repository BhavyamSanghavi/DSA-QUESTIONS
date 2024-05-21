//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x){
        vector<int>ans;
        int ind = lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        if(ind < n){
            if(arr[ind]==x){
                int l = ind-1;
                int r = ind+1;
                while(r < n and l>=0){
                    if(ans.size()==k){
                        return ans;
                    }
                    int diffr = abs(arr[r]-x);
                    int diffl = abs(arr[l]-x);
                    if(diffr <= diffl){
                        ans.push_back(arr[r]);
                        r++;
                    }
                    else{
                        ans.push_back(arr[l]);
                        l--;
                    }
                }
                while(r < n){
                    if(ans.size()==k){
                        return ans;
                    }
                    ans.push_back(arr[r]);
                    r++;
                }
                while(l >=0 ){
                    if(ans.size()==k){
                        return ans;
                    }
                    ans.push_back(arr[l]);
                    l--;
                }
            }
            else{
                int l = ind-1;
                int r = ind;
                while(r < n and l>=0){
                    if(ans.size()==k){
                        return ans;
                    }
                    int diffr = abs(arr[r]-x);
                    int diffl = abs(arr[l]-x);
                    if(diffr <= diffl){
                        ans.push_back(arr[r]);
                        r++;
                    }
                    else{
                        ans.push_back(arr[l]);
                        l--;
                    }
                }
                while(r < n){
                    if(ans.size()==k){
                        return ans;
                    }
                    ans.push_back(arr[r]);
                    r++;
                }
                while(l >=0 ){
                    if(ans.size()==k){
                        return ans;
                    }
                    ans.push_back(arr[l]);
                    l--;
                }
            }
        }
        else{
            int l = ind-1;
            while(l >=0 ){
                if(ans.size()==k){
                    return ans;
                }
                ans.push_back(arr[l]);
                l--;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends