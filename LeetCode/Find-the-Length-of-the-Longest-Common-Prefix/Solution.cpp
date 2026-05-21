1
2class Solution {
3public:
4    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
5        unordered_map<string, int> prefixMap;
6        
7        // Step 1: Build the prefix map for arr1
8        for (int num : arr1) {
9            string strNum = to_string(num);
10            string prefix = "";
11            for (char ch : strNum) {
12                prefix += ch;
13                prefixMap[prefix]++;
14            }
15        }
16        
17        int maxLength = 0;
18        
19        // Step 2: Check for common prefixes in arr2
20        for (int num : arr2) {
21            string strNum = to_string(num);
22            string prefix = "";
23            for (char ch : strNum) {
24                prefix += ch;
25                if (prefixMap.find(prefix) != prefixMap.end()) {
26                    maxLength = max(maxLength, static_cast<int>(prefix.length()));
27                }
28            }
29        }
30        
31        return maxLength;
32    }
33};