1class Solution {
2public:
3string ans="";
4void getBinary(int n, unordered_map<string,bool>&binary, string &temp)
5{
6    if(temp.size()==n)
7    {
8        if(binary.find(temp)==binary.end())
9        {
10            ans=temp;
11        }
12        return;
13    }
14
15    temp.push_back('1');
16    getBinary(n,binary,temp);
17    temp.pop_back();
18    // getBinary(n,binary,temp);
19    temp.push_back('0');
20    getBinary(n,binary,temp);
21    temp.pop_back();
22    // getBinary(n,binary,temp);
23    
24}
25    string findDifferentBinaryString(vector<string>& nums) {
26        int n=nums[0].size();
27        unordered_map<string,bool>binary;
28        for(auto i:nums) binary[i]=1;
29        string temp="";
30        getBinary(n,binary,temp);
31        return ans;
32    }
33};