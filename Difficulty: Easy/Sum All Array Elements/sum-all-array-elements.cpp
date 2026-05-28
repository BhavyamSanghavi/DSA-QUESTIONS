class Solution {
  public:
    int arraySum(vector<int>& arr) {
        // code here
        return accumulate(arr.begin(),arr.end(),0);
    }
};