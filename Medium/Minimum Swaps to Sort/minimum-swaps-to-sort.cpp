//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vector<int>a(nums.begin(),nums.end());
	    sort(a.begin(),a.end());
	    unordered_map<int,int>m;
	    int swaps=0;
	    for(int i=0;i<nums.size();i++) m[nums[i]]=i;
	    
	    for(int i=0;i<nums.size();i++)
	    {
	        if(nums[i]!=a[i])
	        {
	            int index=m[a[i]];
	            m[nums[i]]=index;
	            m[nums[index]]=i;
	            swap(nums[index],nums[i]);
	            swaps++;
	        }
	    }
	    return swaps;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends