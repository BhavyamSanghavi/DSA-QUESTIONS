1class Solution {
2public:
3    static bool comp(vector<int>a, vector<int>b)
4    {
5        if(a[0]!=b[0]) return a[0]<b[0];
6        else return a[1]>b[1];
7    }
8    int removeCoveredIntervals(vector<vector<int>>& intervals) {
9        sort(intervals.begin(),intervals.end(),comp);
10        
11        vector<vector<int>> v;
12        v.push_back(intervals[0]);
13
14        int ans=0;
15        for(int i=1;i<intervals.size();i++)
16        {
17            if(intervals[i][0]>=v.back()[0] && intervals[i][0]<=v.back()[1] &&
18                intervals[i][1]>=v.back()[0] && intervals[i][1]<=v.back()[1])
19                ans++;
20            else
21                v.push_back(intervals[i]);
22        }
23        return intervals.size()-ans;
24    }
25};