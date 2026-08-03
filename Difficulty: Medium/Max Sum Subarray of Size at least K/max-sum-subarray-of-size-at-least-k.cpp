class Solution {
  public:
    int maxSumWithK(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>best(n);
        best[0]=arr[0];
        for(int i=1;i<n;i++)
            best[i]=max(arr[i],best[i-1]+arr[i]);
        
        int winsum=0;
        for(int i=0;i<k;i++)
            winsum+=arr[i];
        
        int ans=winsum;
        for(int i=1;i<=n-k;i++)
        {
            winsum-=arr[i-1];
            winsum+=arr[i+k-1];
            
            ans=max(ans,winsum);
            ans=max(ans,winsum+best[i-1]);
        }
        
        return ans;
    }
};