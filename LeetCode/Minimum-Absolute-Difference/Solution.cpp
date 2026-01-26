1class Solution {
2public:
3    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
4        vector<vector<int>>ans;
5        sort(arr.begin(),arr.end());
6        int diff=arr[1]-arr[0];
7        ans.push_back({arr[0],arr[1]});
8
9        for(int i=1;i<arr.size()-1;i++)
10        {
11            int currDiff=arr[i+1]-arr[i];
12            if(currDiff>diff) continue;
13            else if(currDiff==diff) ans.push_back({arr[i],arr[i+1]});
14            else 
15            {
16                while(ans.size()>0)
17                    ans.pop_back();
18                ans.push_back({arr[i],arr[i+1]});
19                diff=currDiff;
20            }
21        }
22        return ans;
23    }
24};