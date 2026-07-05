1class Solution {
2public:
3    int maxValidPairSum(vector<int>& nums, int k) {
4        vector<int>postMax(nums.size());
5        
6        postMax[nums.size()-1]=nums[nums.size()-1];
7        
8        for(int i=nums.size()-2;i>=0;i--)
9            postMax[i]=max(postMax[i+1],nums[i]);
10
11        int ans=0;
12        for(int i=0;i<nums.size()-k;i++)
13            ans=max(ans,nums[i]+postMax[i+k]);
14        
15        return ans;
16    }
17}; 