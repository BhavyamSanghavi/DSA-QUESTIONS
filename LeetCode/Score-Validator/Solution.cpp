1class Solution {
2public:
3    vector<int> scoreValidator(vector<string>& events) {
4        int counter=0, score=0;
5
6        for(string& s:events)
7        {
8            if(s=="W") counter++;
9            else if(s=="WD" || s=="NB") score++;
10            else 
11            {
12                int n=stoi(s);
13                score+=n;
14            }
15            if(counter>=10) break;
16        }
17        return {score,counter};
18    }
19};