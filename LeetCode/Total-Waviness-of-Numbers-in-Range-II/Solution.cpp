1using ll = long long;
2class Solution {
3    static inline int waves[570];
4    static inline bool init = []() {
5        int j = 0;
6        for (int i = 0; i < 1000; i++) {
7            int r = i % 10;
8            int m = (i / 10) % 10;
9            int l = (i / 100) % 10;
10            if ((m > max(l, r)) | (m < min(l, r)))
11                waves[j++] = i;
12        }
13        return 0;
14    }();
15
16public:
17    ll totalWaviness(ll A, ll B) { return waveCount(B) - waveCount(A - 1); }
18
19private:
20    ll waveCount(ll num) {
21        if (num < 100)
22            return 0;
23        ll res = 0;
24        for (auto& p : waves)
25            res += countWays(num, p);
26        return res;
27    }
28
29    ll countWays(ll num, int pattern) {
30        ll type = pattern < 100;
31        ll count = 0, mult = 1;
32
33        for (int i = 0; i < 16; i++) {
34            if (mult * 100 > num)
35                break;
36
37            ll pre = num / (mult * 1000);
38            ll cur = (num / mult) % 1000;
39            ll suf = num % mult;
40
41            ll ways = 0, edge = 0;
42
43            if (cur > pattern)
44                ways = pre - type + 1;
45            else if (cur == pattern) {
46                ways = max(0LL, pre - type);
47                edge = (pre >= type) * (suf + 1);
48            } else if (cur < pattern)
49                ways = max(0LL, pre - type);
50
51            count += ways * mult + edge;
52            mult *= 10;
53        }
54
55        return count;
56    }
57};