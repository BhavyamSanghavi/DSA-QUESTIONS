1class Solution {
2public:
3    bool asteroidsDestroyed(int m, vector<int>& asteroids) {
4        long long int mass=m;
5        sort(asteroids.begin(),asteroids.end());
6        int i=0;
7        while(i<asteroids.size())
8        {
9            if(asteroids[i]>mass) return false;
10            else mass+=asteroids[i++];
11        }
12        return true;
13    }
14};