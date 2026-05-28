// User function Template for C++

class Solution {
  public:
    int toyCount(int N, int K, vector<int> arr) {
        sort(arr.begin(), arr.end());
        int ans = 0;
        int i = 0;
        while(i<arr.size() && K>0){
            if(K-arr[i]>=0) {
                K -= arr[i];
                ans++;
            }
            i++;
        }
        return ans;
    }
};