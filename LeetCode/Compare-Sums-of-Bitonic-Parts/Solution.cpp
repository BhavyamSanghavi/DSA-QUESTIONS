1class Solution {
2public:
3    int compareBitonicSums(vector<int>& nums) {
4        // int total=accumulate(nums.begin(),nums.end(),0);
5        long long sum=0,i=0,sum2=0;
6
7        while(i<nums.size()-1 && nums[i]<nums[i+1])
8        {
9            sum+=nums[i++];
10        }
11        i++;
12        while(i<nums.size()) sum2+=nums[i++];
13
14        if(sum>sum2) return 0;
15        if(sum2>sum) return 1;
16        return -1;
17    }
18};