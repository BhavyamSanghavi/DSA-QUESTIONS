//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void nextPermutation(vector<int>& nums) {
        int len=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>=nums[i+1])
            {
                len++;
            }
        }
        if(len==nums.size()-1)    {reverse(nums.begin(),nums.end()); return;}
        int maxi=0, secmax;

        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<nums[i+1])
            {
                secmax=i;
            }
        }
        for(int i=secmax;i<nums.size();i++)
        {
            if(nums[secmax]<nums[i])
            {
                maxi=i;
            }
        }
        swap(nums[maxi],nums[secmax]);
        reverse(nums.begin()+secmax+1,nums.end());
        // return nums;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends