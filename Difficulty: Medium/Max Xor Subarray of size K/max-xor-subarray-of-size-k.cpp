class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int ans=0,currxor=0;
        for(int i=0;i<k;i++) currxor^=arr[i];
        ans=currxor;
        for(int i=k;i<arr.size();i++)
        {
            currxor^=arr[i-k];
            currxor^=arr[i];
            ans=max(ans,currxor);
        }
        return ans;
    }
};