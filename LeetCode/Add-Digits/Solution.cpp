1class Solution {
2public:
3    int addDigits(int num) {
4        string n=to_string(num);
5        while(n.size()>1)
6        {
7            int sum=0;
8            for(int i=0;i<n.size();i++)
9                sum+=n[i]-'0';
10            n=to_string(sum);
11        }
12        num=stoi(n);
13        return num;
14    }
15};