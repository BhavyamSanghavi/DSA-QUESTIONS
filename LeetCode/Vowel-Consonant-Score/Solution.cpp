1class Solution {
2public:
3    bool isVowel(char i)
4    {
5        if(i=='a' || i=='e' || i=='i' || i=='o' || i=='u') return 1;
6        return 0;
7    }
8    int vowelConsonantScore(string s) {
9        int v=0,c=0;
10        for(char i:s)
11        {
12            if(i>='a' && i<='z')
13            {
14                if(isVowel(i)) ++v;
15                else ++c;
16            }
17            else continue;
18        }
19        if(c==0) return 0;
20        return floor(v/c);
21    }
22};