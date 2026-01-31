1class Solution {
2public:
3    char nextGreatestLetter(vector<char>& letters, char target) {
4        for(char i:letters)
5            if(i>target) return i;
6        return letters[0];
7    }
8};