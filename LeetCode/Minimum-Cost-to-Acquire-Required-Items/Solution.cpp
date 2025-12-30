1class Solution {
2public:
3    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
4        long long ans=0;
5        int minNeed=min(need1,need2);
6        ans+=minNeed*min((long long)cost1+cost2,(long long)costBoth);
7        need1-=minNeed;
8        need2-=minNeed;
9
10        if(need1) ans+=need1*min((long long)cost1,(long long)costBoth);
11        if(need2) ans+=need2*min((long long)cost2,(long long)costBoth);
12
13        return ans;
14    }
15};