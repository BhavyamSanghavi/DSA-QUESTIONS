1class Solution {
2public:
3    vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals)
4    {
5        sort(intervals.begin(),intervals.end());
6        vector<vector<int>>res;
7        res.push_back(intervals[0]);
8
9        for(int i=1;i<intervals.size();i++)
10        {
11            if(res[res.size()-1][1]>=intervals[i][0])
12                res[res.size()-1][1]=max(res[res.size()-1][1],intervals[i][1]);
13            else
14                res.push_back(intervals[i]);
15        }
16        return res;
17    }
18    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
19        int bulbs=ceil(brightness/3.0);
20        intervals=mergeIntervals(intervals);
21
22        int time=0;
23        for(auto i:intervals)
24            time+=i[1]-i[0]+1;
25        
26        return (long long)bulbs*time;
27    }
28};