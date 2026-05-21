1#include <bits/stdc++.h>
2using namespace std;
3
4class Solution {
5public:
6    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
7        unordered_map<string, int> prefixMap;
8        
9        // Step 1: Build the prefix map for arr1
10        for (int num : arr1) {
11            string strNum = to_string(num);
12            string prefix = "";
13            for (char ch : strNum) {
14                prefix += ch;
15                prefixMap[prefix]++;
16            }
17        }
18        
19        int maxLength = 0;
20        
21        // Step 2: Check for common prefixes in arr2
22        for (int num : arr2) {
23            string strNum = to_string(num);
24            string prefix = "";
25            for (char ch : strNum) {
26                prefix += ch;
27                if (prefixMap.find(prefix) != prefixMap.end()) {
28                    maxLength = max(maxLength, static_cast<int>(prefix.length()));
29                }
30            }
31        }
32        
33        return maxLength;
34    }
35};