1class Solution {
2public:
3    int minPartitions(string n) {
4        int maxi=0;
5        for(char i:n) maxi=max(maxi,i-'0');
6        return maxi;
7    }
8};