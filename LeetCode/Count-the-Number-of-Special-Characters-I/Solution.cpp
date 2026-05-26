1class Solution {
2public:
3    int numberOfSpecialChars(string word) {
4        unordered_map<char,int>m;
5        
6        for(char i:word)
7            if(i>='a' && i<='z') m[i]=1;
8        
9        for(char i:word)
10            if(i>='A' && i<='Z' && m[tolower(i)]) m[tolower(i)]++;
11        
12        int ans=0;
13        for(auto i:m)
14            if(i.second>=2) ans++;
15        
16        return ans;
17    }
18};