1class Solution {
2public:
3    int largestAltitude(vector<int>& gain) {
4        int curr=0,maxi=0;
5        for(int i=0;i<gain.size();i++)
6        {
7            curr+=gain[i];
8            maxi=max(maxi,curr);
9        }
10        return maxi;
11    }
12};