class Solution {
  public:
    void sortIt(vector<int>& arr) {
        // code here
        int n = arr.size();
        int j = 0;

        // Partition odd in front
        for(int i = 0; i < n; i++) {
            if(arr[i] & 1) {
                swap(arr[i], arr[j]);
                j++;
            }
        }

        // Sort odd in descending
        sort(arr.begin(), arr.begin() + j, greater<int>());

        // Sort even in ascending
        sort(arr.begin() + j, arr.end());
    }
};