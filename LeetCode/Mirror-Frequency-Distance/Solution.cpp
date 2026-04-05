1class Solution {
2public:
3    char getMirror(char ch)
4    {
5        if(ch>='a' && ch<='z')
6            return 'z'-(ch-'a');
7        else 
8            return '9'-(ch-'0');
9    }
10    int mirrorFrequency(string s) {
11        unordered_map<char,int>freq;
12        for(char i:s) freq[i]++;
13
14        unordered_set<char>visited;
15        int ans=0;
16
17        for(char i:s)
18        {
19            if(visited.find(i)==visited.end())
20            {
21                char mirror=getMirror(i);
22                ans+=abs(freq[i]-freq[mirror]);
23
24                visited.insert(i);
25                visited.insert(mirror);
26            }
27        }
28
29        return ans;
30    }
31};