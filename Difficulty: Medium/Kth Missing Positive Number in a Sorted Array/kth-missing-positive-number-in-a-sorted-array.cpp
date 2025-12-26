class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // code here
         int n = arr.size();
        
        // for first element 
        int k_first = arr[0] - 1;
        if(k_first >= k) return k;
        
        // for last element
        int k_last = arr[n-1] - n;
        if(k_last < k) return arr[n-1] - k_last + k;
        
        int s = 0, e = n-1;
        while(s <= e) {
            int mid = (s+e) / 2;
            int k_temp = arr[mid] - mid - 1;
            
            if(k_temp < k) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }
        
        int k_temp = arr[e] - e - 1;
        return arr[e] - k_temp + k;
    }
};