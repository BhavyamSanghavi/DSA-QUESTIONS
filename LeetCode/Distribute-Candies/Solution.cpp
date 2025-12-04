1class Solution {
2public:
3    int distributeCandies(vector<int>& candyType) {
4        unordered_set<int>s(candyType.begin(),candyType.end());
5        return min(candyType.size()/2, s.size());
6    }
7};