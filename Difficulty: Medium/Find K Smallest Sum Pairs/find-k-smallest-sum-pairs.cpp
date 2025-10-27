class Solution {
  public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
    vector<vector<int>> ans;
    int n = arr1.size(), m = arr2.size();
    
    // min-heap: {sum, {i, j}}
    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>> > pq;
    
    // set to avoid pushing duplicates
    set<pair<int, int>> visited;
    
    pq.push({arr1[0] + arr2[0], {0, 0}});
    visited.insert({0, 0});
    
    while(k-- && !pq.empty()) {
        auto top = pq.top(); pq.pop();
        int i = top.second.first, j = top.second.second;
        ans.push_back({arr1[i], arr2[j]});
        
        // next pair in arr1
        if(i + 1 < n && !visited.count({i + 1, j})) {
            pq.push({arr1[i + 1] + arr2[j], {i + 1, j}});
            visited.insert({i + 1, j});
        }
        // next pair in arr2
        if(j + 1 < m && !visited.count({i, j + 1})) {
            pq.push({arr1[i] + arr2[j + 1], {i, j + 1}});
            visited.insert({i, j + 1});
        }
    }
    
    return ans;
}

};
