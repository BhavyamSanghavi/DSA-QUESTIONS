1class Solution {
2public:
3    int minimumPushes(string word) {
4        int freq[26]={0};
5    
6        for(char c: word) 
7            freq[c-'a']++;
8        sort(freq, freq+26, greater<int>());
9    
10        int sz=0, push=1, ans=0;
11        for(; sz<26 && freq[sz]!=0; sz++){
12            if (sz>=8 && sz%8==0) push++;
13            ans+=freq[sz]*push;    
14        }
15        return ans;
16    }
17};