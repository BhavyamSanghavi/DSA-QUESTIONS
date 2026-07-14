1class Solution {
2public:
3    int secondsBetweenTimes(string startTime, string endTime) {
4        long long int end=0, start=0;
5        int h=stoi(endTime.substr(0,2));
6        int m=stoi(endTime.substr(3,5));
7        int s=stoi(endTime.substr(6,8));
8        
9        end=h*60*60+m*60+s;
10        
11        h=stoi(startTime.substr(0,2));
12        m=stoi(startTime.substr(3,5));
13        s=stoi(startTime.substr(6,8));
14
15        start=h*60*60+m*60+s;
16
17        return end-start;
18    }
19};