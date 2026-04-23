class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        int sum=accumulate(arr.begin(), arr.end(), 0);
        if(sum%2==1) return false;
        sum/=2;
        
        int curr=0;
        for(int i=0;i<arr.size();i++)
        {
            curr+=arr[i];
            if(curr==sum) return true;
            else if(curr>sum) return false;
        }
        return false;
    }
};
