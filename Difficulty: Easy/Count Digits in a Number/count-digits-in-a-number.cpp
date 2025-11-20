class Solution {
  public:
    int countDigits(int n) {
        // Code here
        return to_string(n).size();
    }
};