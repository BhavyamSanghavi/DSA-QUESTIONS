//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
         int xor1 = 0;
        for (unsigned i = 0; i < nums.size(); i++) {
            xor1 ^= nums[i];
        }
        int small = 0;
        int large = 0;
        for (unsigned i = 0; i < nums.size(); i++) {
            auto b = nums[i] ^ xor1;

            if (nums[i] < b)
            {
                small ^= nums[i];
            }
            if (nums[i] > b)
            {
                large ^= nums[i];
            }
        }
        return vector<int>{small, large};
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends