class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
        // code here
        int noDelete = arr[0];
        int oneDelete = arr[0];
        int ans = arr[0];

        for (int i = 1; i < arr.size(); i++) {

            oneDelete = max(noDelete, oneDelete + arr[i]);
            noDelete = max(arr[i], noDelete + arr[i]);

            ans = max(ans, max(noDelete, oneDelete));
        }

        return ans;
    }
};