1class Solution {
2public:
3    int getReverse(int n)
4    {
5        string s=to_string(n);
6        while(s[s.size()-1]=='0') s.pop_back();
7        reverse(s.begin(),s.end());
8        return stoi(s);
9    }
10    int minMirrorPairDistance(vector<int>& nums) {
11        int ans=1e9;
12        unordered_map<int,int>m;
13        for(int i=0;i<nums.size();i++)
14        {
15            int n=getReverse(nums[i]);
16            if(m.find(nums[i])!=m.end())
17                ans=min(ans,abs(m[nums[i]]-i));
18            m[n]=i;
19        }
20        if(ans==1e9) return -1;
21        return ans;
22    }
23};