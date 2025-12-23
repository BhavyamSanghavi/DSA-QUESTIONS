class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        vector<int>ans;
        sort(arr.begin(),arr.end());
        for(auto query:queries)
        {
            int low=lower_bound(arr.begin(),arr.end(),query[0])-arr.begin();
            int high=upper_bound(arr.begin(),arr.end(),query[1])-arr.begin();
            int count=high-low;
            ans.push_back(count);
        }
        return ans;
    }
    
};