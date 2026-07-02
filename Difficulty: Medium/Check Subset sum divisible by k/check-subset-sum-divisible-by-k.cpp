class Solution {
  public:
    int memo[1001][1001];

bool solve(vector<int>& arr, int k, int index, int current_remainder, bool is_empty) {
    // Base case: processed all elements
    if (index == arr.size()) {
        return (!is_empty && (current_remainder == 0));
    }

    // Check if result is already computed
    // We only memoize when we are not in the "is_empty" state 
    // to keep the state representation simple.
    if (!is_empty && memo[index][current_remainder] != -1) {
        return memo[index][current_remainder];
    }

    // Include the current element
    bool include = solve(arr, k, index + 1, (current_remainder + arr[index]) % k, false);
    
    // Exclude the current element
    bool exclude = solve(arr, k, index + 1, current_remainder, is_empty);

    bool result = include || exclude;

    // Store in memo table
    if (!is_empty) {
        memo[index][current_remainder] = result;
    }
    
    return result;
}

    bool divisibleByK(vector<int>& arr, int k) {
        for(int i = 0; i <= arr.size(); ++i) {
            for(int j = 0; j < k; ++j) {
                memo[i][j] = -1;
            }
        }
        return solve(arr, k, 0, 0, true);
        
    }
};