1class Solution {
2public:
3    int minOperations(string s) {
4        int sz=0;
5        for(int i=0;i<s.size();i++)
6        {
7            if(i%2!=0 && s[i]=='0')sz++;
8            else if(i%2==0 && s[i]=='1')sz++;            
9        }
10        // int so=0;
11        // for(int i=0;i<s.size();i++)
12        // {
13        //     if(i%2!=0 && s[i]=='1')so++;
14        //     else if( i%2==0 && s[i]=='0')so++;            
15        // }
16        // cout<<sz<<"  "<<so<<endl;
17        int n=s.size();
18        return min(sz,n-sz);
19    }
20};