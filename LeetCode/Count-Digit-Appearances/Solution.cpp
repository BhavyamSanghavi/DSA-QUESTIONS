1class Solution {
2public:
3    int countDigitOccurrences(vector<int>& nums, int digit) {
4        int ans=0;
5        char d=digit+'0';
6        for(int i:nums)
7        {
8            string num=to_string(i);
9            int count=std::count(num.begin(),num.end(),d);
10            ans+=count;
11        }
12        return ans;
13    }
14};