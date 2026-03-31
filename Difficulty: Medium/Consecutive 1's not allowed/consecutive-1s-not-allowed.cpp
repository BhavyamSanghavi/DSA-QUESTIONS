class Solution {
  public:
    int countStrings(int n) {
        int a=1,b=1,ans=0;
        while(n--)
        {
            ans=a+b;
            a=b;
            b=ans;
        }
        return ans;
    }
};
