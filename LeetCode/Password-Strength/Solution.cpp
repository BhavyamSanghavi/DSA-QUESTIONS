1class Solution {
2public:
3    int passwordStrength(string password) {
4        unordered_set<char>s(password.begin(),password.end());
5        int strength=0;
6        for(auto i:s)
7        {
8            if(i>='a' && i<='z') strength+=1;
9            else if(i>='A' && i<='Z') strength+=2;
10            else if(i>='0' && i<='9') strength+=3;
11            else strength+=5;
12        }
13        return strength;
14    }
15};