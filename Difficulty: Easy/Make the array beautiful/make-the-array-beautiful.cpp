class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        vector<int>ans;
        for(int i=0;i<arr.size();i++)
        {
            if(ans.size()==0)
            {
                ans.push_back(arr[i]);
                continue;
            }
            if((ans.back()>=0 && arr[i]>=0) || (ans.back()<0 && arr[i]<0))
                ans.push_back(arr[i]);
            else
                ans.pop_back();
        }
        return ans;
    }
};