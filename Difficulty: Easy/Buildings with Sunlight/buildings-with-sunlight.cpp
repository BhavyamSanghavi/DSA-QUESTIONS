class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        // code here
        int maxi=0,ans=0;
        for(int i=0;i<arr.size();i++)
        {
            if(maxi<=arr[i])
            {
                maxi=arr[i];
                ans++;
            }
        }
        return ans;
    }
};