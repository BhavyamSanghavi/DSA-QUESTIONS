class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int ans=0,sum=0;
        for(int i=0;i<k;i++) sum+=arr[i];
        ans=sum;
        for(int i=k;i<arr.size();i++)
        {
            sum+=arr[i];
            sum-=arr[i-k];
            ans=max(ans,sum);
        }
        return ans;
    }
};