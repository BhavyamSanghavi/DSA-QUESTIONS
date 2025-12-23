1class Solution {
2public:
3    int maxTwoEvents(vector<vector<int>>& events) {
4    int res = 0, max_val = 0;
5    priority_queue<pair<int, int>> pq;
6    sort(begin(events), end(events));
7    for (auto &e : events) {
8        for(; !pq.empty() && -pq.top().first < e[0]; pq.pop())
9            max_val = max(max_val, pq.top().second);
10        res = max(res, max_val + e[2]);
11        pq.push({-e[1], e[2]});
12    }
13    return res;
14}
15};