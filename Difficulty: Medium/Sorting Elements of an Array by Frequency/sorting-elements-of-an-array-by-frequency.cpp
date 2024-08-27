//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    static bool comp(pair<int,int> a,pair<int,int> b)
    {
        if(a.first>b.first) return true;
        if(a.first < b.first) return false;
        return a.second < b.second;
    }
    vector<int> sortByFreq(vector<int>& arr) {
        vector<int>ans;
        vector<pair<int,int>>v;
        unordered_map<int,int>m;
        
        for(auto i:arr) m[i]++;
        
        for(auto i:m)
        {
            v.push_back({i.second,i.first});
        }
        sort(v.begin(), v.end(),comp);
        
        // for(auto i:v)
        // {
        //     cout<<i.first<<"  "<<i.second<<endl;
        // }
        
        for(auto i:v)
        {
            int freq=i.first, num=i.second;
            while(freq--)
            {
                ans.push_back(num);
            }
        }
        
        return ans;
        
        
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
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends