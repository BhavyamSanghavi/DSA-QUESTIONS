class Solution {
public:
    bool check(long long x,long long k,long long lim){
        if(lim<0)return false;
        long long res=1;
        while(k>0){
            if(k&1){
                if(res>lim/x)return false;
                res*=x;   
            }
            k>>=1;
            if(k>0){
                if(x>lim/x)x=lim+1;
                else x*=x;
            }
        }
        return x<=lim;
    }
    
    int countKthRoots(int l, int r, int k) {
        if(l>r)return 0;
        long long lo=1,hi=1e9,maxi=0;
        while(lo<=hi){
            long long mid=lo+(hi-lo)/2;
            if(check(mid,k,r)){
                maxi=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        lo=1,hi=1e9;
        long long mini=0;
        while(lo<=hi){
              long long mid=lo+(hi-lo)/2;
            if(check(mid,k,l-1)){
                mini=mid;
                    lo=mid+1;
            }
            else hi=mid-1;
        }
        int ans=0;
        if(l<=0 && 0<=r)ans++;
        return maxi-mini+ans;
    }
};