1class Solution {
2public:
3    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
4        int i,j;
5        for(i=0, j=0;i<nums1.size() && j<nums2.size(); j++)
6            i+=nums1[i]>nums2[j];
7        return max(0,j-i-1);
8    }
9};