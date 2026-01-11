class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        vector<int>ans;
        priority_queue<pair<int,int>>q;
        for(int i=0;i<k;i++) q.push({arr[i],i});
        ans.push_back(q.top().first);
        for(int i=k;i<arr.size();i++)
        {
            q.push({arr[i],i});
            while(q.top().second<=i-k) q.pop();
            ans.push_back(q.top().first);
        }
        return ans;
    }
};