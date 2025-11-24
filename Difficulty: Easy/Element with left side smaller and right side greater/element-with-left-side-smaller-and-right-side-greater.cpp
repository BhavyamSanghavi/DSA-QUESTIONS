class Solution {
  public:
    int findElement(vector<int> &arr) {
         int index = -1, max = 0, candidate = -1;
        for (int i=0; i < arr.size(); ++i) {
            if (arr[i] > max && candidate == -1) {
                index = i;
                max = arr[i];
                candidate = max;
            }
            if (arr[i] >= max) {
                max = arr[i];
                continue;
            }
            index = i;
            candidate = -1;
        }
        if (index == 0 || index == arr.size()-1) return -1;
        return candidate;
    }
};