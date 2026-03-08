1class Solution {
2public:
3    int minimumIndex(vector<int>& capacity, int itemSize) {
4        int diff=1e9,index=-1;
5        for(int i=0;i<capacity.size();i++)
6        {
7            if(capacity[i]>=itemSize)
8            {
9                if(diff>capacity[i]-itemSize)
10                {
11                    diff=capacity[i]-itemSize;
12                    index=i;
13                }
14            }
15        }
16        return index;
17    }
18};