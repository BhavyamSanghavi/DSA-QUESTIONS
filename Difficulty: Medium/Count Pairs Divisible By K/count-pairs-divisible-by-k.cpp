class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int ans = 0;
        vector<int> mpp(k);
        for(auto it : arr)
        {
            ans += mpp[it%k];
            mpp[(-it%k + k)%k]++;
        }
        return ans;
    }
};