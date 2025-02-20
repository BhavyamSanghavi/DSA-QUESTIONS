//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  double solve(priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int>> &minHeap, int element)
{
    // Edge Case: If maxHeap is empty, push directly to it
    if (maxHeap.empty() || element <= maxHeap.top())
    {
        maxHeap.push(element);
        // cout << "Pushed " << element << " in maxHeap" << endl;
    }
    else
    {
        minHeap.push(element);
        // cout << "Pushed " << element << " in minHeap" << endl;
    }

    // Balance the heaps if maxHeap has more than one extra element
    if (maxHeap.size() > minHeap.size() + 1)
    {
        int x = maxHeap.top();
        maxHeap.pop();
        minHeap.push(x);
    }
    else if (minHeap.size() > maxHeap.size()) // Balance the heaps if minHeap has more elements
    {
        int x = minHeap.top();
        minHeap.pop();
        maxHeap.push(x);
    }

    // Return median
    if (maxHeap.size() == minHeap.size())
        return (maxHeap.top() + minHeap.top()) / 2.0;
    else
        return (double)maxHeap.top();
}
  
    vector<double> getMedian(vector<int> &arr) {
        priority_queue<int>maxHeap;
        priority_queue<int,vector<int>,greater<int>>minHeap;
        
        vector<double>ans;
        maxHeap.push(arr[0]);
        ans.push_back((double)arr[0]);
        for(int i=1;i<arr.size();i++)
            ans.push_back(solve(maxHeap,minHeap,arr[i]));
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends