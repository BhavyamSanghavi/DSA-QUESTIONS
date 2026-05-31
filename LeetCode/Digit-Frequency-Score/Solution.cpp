1class Solution {
2public:
3    int digitFrequencyScore(int n) {
4        unordered_map<int,int>m;
5        string num=to_string(n);
6        
7        for(int i=0;i<num.size();i++)
8        {
9            int digit=num[i]-'0';
10            m[digit]++;
11        }
12
13        int ans=0;
14        for(auto i:m)
15            ans+=i.first*i.second;
16        
17        return ans;
18    }
19};