1class Solution {
2public:
3    int findMin(vector<int>& nums) {
4        int n = nums.size() - 1;
5        int last = nums[n];
6        int left = 0, right = n;
7
8        while (left < n && nums[left] == last)
9            left++;
10
11        while (left < right) {
12            int mid = left + right >> 1;
13
14            if (nums[mid] > last)
15                left = mid + 1;
16            else
17                right = mid;
18        }
19
20        return nums[left];
21    }
22};