1class Solution {
2public:
3    vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals)
4    {
5        sort(intervals.begin(),intervals.end());
6        
7        vector<vector<int>>res;
8        res.push_back(intervals[0]);
9
10        for(int i=1;i<intervals.size();i++)
11        {
12            if(res[res.size()-1][1]>=intervals[i][0])
13                res[res.size()-1][1]=max(res[res.size()-1][1],intervals[i][1]);
14            else
15                res.push_back(intervals[i]);
16        }
17        
18        return res;
19    }
20    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
21        int bulbs=ceil(brightness/3.0);
22        intervals=mergeIntervals(intervals);
23
24        int time=0;
25        for(auto i:intervals)
26            time+=i[1]-i[0]+1;
27        
28        return (long long)bulbs*time;
29    }
30};