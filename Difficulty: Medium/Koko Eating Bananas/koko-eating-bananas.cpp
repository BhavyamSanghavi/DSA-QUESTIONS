class Solution {
  public:
    int kokoEat(vector<int>& piles, int h) {
        
        int l=1, r=1000000000;
        while(l<r)
        {
            int m=(l+r)/2;
            int total=0;
            for(int p:piles)    total+=(p+m-1)/m;
            if(total>h) l=m+1;
            else r=m;
        }
        return l;
        
    }
};