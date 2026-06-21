1class Solution {
2public:
3    int maxIceCream(vector<int>& costs, int coins) {
4        int ans=0;
5        sort(costs.begin(),costs.end());
6        for(int i=0;i<costs.size();i++)
7        {
8            if(coins>=costs[i])
9            {
10                coins-=costs[i];
11                ans++;
12            }
13            else break;
14        }
15        
16        return ans;
17    }
18};