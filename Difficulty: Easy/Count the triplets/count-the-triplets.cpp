class Solution {
  public:
    int countTriplet(vector<int>& arr) {
        // code here
        if(arr.size()<3) return 0;
        sort(arr.begin(), arr.end());
        int ans = 0;
        
        for(int i = 2;i<arr.size();i++){
            int j = 0;
            int k = i - 1;
            while(j<k){
                int sum = arr[j] + arr[k];
                if(sum==arr[i]){
                    ans++;
                    j++;
                    k--;
                }
                else if(sum>arr[i]){
                    k--;
                }
                else j++;
            }
        }
        return ans;
    }
};