1class Solution {
2public:
3    vector<int> toggleLightBulbs(vector<int>& bulbs) {
4        unordered_map<int,bool>m;
5        for(int i:bulbs)
6        {
7            if(m.find(i)==m.end()) m[i]=true;
8            else m[i]=!m[i];
9        }
10        vector<int>ans;
11        for(auto i:m)
12        {
13            if(i.second==true) ans.push_back(i.first);
14        }
15        sort(ans.begin(),ans.end());
16        return ans;
17    }
18};