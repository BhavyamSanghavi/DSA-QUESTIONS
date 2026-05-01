class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>ans(n,-1);
        
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<k-1;i++) pq.push(arr[i]);
        
        for(int i=k-1;i<n;i++)
        {
            pq.push(arr[i]);
            if(pq.size()>k) pq.pop();
            ans[i]=pq.top();
        }
        return ans;
    }
};