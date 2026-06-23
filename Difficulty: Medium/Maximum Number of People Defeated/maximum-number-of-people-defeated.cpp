class Solution {
  public:
    int maxPeopleDefeated(int p) {
        int ans=0;
        int i=1;
        while(i*i<=p)
        {
            p-=i*i;
            ans++;
            i++;
        }
        return ans;
    }
};
