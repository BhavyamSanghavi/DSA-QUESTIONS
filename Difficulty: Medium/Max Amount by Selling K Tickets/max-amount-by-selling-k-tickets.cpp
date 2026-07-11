class Solution {
  public:
    const int mod=1e9+7;
    int maxAmount(vector<int>& arr, int k) {
        priority_queue<int>pq(arr.begin(),arr.end());
        
        int ans=0;
        while(k--)
        {
            int ele=pq.top(); pq.pop();
            ans=(ans+ele)%mod;
            pq.push(max(0,ele-1));
        }
        return ans%mod;
    }
};