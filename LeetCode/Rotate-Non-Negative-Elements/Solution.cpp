1class Solution {
2public:
3    vector<int> rotateElements(vector<int>& nums, int k) {
4        vector<int>positive;
5        
6        for(int i:nums)
7            if(i>=0) positive.push_back(i);
8        
9        vector<int>dup=positive;
10        int n=positive.size();
11        for(int i=0;i<positive.size();i++)
12            dup[i]=positive[((i+k)%n)];
13        
14        int ind=0;
15        for(int i=0;i<nums.size();i++)
16            if(nums[i]>=0) nums[i]=dup[ind++];
17        return nums;
18    }
19};