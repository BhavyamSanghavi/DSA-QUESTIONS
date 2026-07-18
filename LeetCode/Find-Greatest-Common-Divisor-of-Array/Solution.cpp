1class Solution {
2public:
3    int findGCD(vector<int>& nums) {
4        int small=*min_element(nums.begin(),nums.end());
5        int big=*max_element(nums.begin(),nums.end());
6        return gcd(small,big);
7    }
8};