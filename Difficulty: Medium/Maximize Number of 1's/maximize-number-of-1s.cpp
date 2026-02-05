class Solution {
  public:
    int maxOnes(vector<int>& arr, int m) {
        // code here
        int zeroes =0, len=0,l=0,r=0,maxLen=0;
        int n=arr.size();
        while(r<n) {
            if(arr[r]==0) zeroes++;
            if(zeroes>m) {
                if(arr[l]==0) zeroes--;
                l++;
            }
            if(zeroes<=m) {
                len = r-l+1;
                maxLen = max(maxLen,len);
            }
            r++;
        }
        return maxLen;
    }
};
