class Solution {
  public:
    int derangeCount(int n) {
        // code here
        int temp = 1, ans = 0;
        for(int i=2; i<=n; i++) temp *= i;
        for(int i=2; i<=n; i++) {
            temp /= i;
            if(i%2) ans -= temp;
            else ans += temp;
        }
        return ans;
    }
};