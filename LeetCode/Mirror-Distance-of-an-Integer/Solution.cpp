1class Solution {
2public:
3    int mirrorDistance(int n) {
4        string s=to_string(n);
5        reverse(s.begin(),s.end());
6        int num=stoi(s);
7        return abs(num-n);
8    }
9};