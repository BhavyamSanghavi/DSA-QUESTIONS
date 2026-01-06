class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        vector<int>ans;
        unordered_map<int,int>unique;
        for(int i=0;i<k;i++) unique[arr[i]]++;
        ans.push_back(unique.size());
        for(int i=k;i<arr.size();i++)
        {
            if(--unique[arr[i-k]]==0) unique.erase(arr[i-k]);
            unique[arr[i]]++;
            ans.push_back(unique.size());
        }
        return ans;
    }
};