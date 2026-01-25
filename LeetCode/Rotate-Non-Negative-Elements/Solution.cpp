1class Solution {
2public:
3    vector<int> rotateElements(vector<int>& nums, int k) {
4        vector<int>positive;
5        for(int i:nums)
6            if(i>=0) positive.push_back(i);
7        vector<int>dup=positive;
8        int n=positive.size();
9        for(int i=0;i<positive.size();i++)
10        {
11            dup[i]=positive[((i+k)%n)];
12        }
13        int ind=0;
14        for(int i=0;i<nums.size();i++)
15        {
16            if(nums[i]>=0) nums[i]=dup[ind++];
17        }
18        return nums;
19    }
20};