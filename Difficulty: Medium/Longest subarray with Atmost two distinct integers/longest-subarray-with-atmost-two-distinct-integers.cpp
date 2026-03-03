class Solution {
  public:
    int totalElements(vector<int> &arr) {
        int start=0,end=0,ans=0;
        unordered_map<int,int>m;
        while(end<arr.size())
        {
            m[arr[end]]++;
            while(m.size()>2)
            {
                m[arr[start]]--;
                if(m[arr[start]]==0) m.erase(arr[start]);
                start++;
            }
            ans=max(ans,end-start+1);
            end++;
        }
        return ans;
    }
};