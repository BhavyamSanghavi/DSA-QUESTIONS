class Solution {
  public:
    bool isPalindrome(int n) {
        string s=to_string(n);
        string rev=s;
        reverse(s.begin(),s.end());
        return s==rev;
    }
};