class Solution {
  public:
    int findFirst(const vector<int>& arr, int element, int start, int end) {
    int firstIdx = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == element) {
            firstIdx = mid;
            end = mid - 1; // Keep searching on the left side
        } else if (arr[mid] < element) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return firstIdx;
}

// Helper function to find the last occurrence of the element
int findLast(const vector<int>& arr, int element, int start, int end) {
    int lastIdx = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == element) {
            lastIdx = mid;
            start = mid + 1; // Keep searching on the right side
        } else if (arr[mid] < element) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return lastIdx;
}

int binaryCount(vector<int>& arr, int element, int start, int end) {
    // Validate range
    if (start > end || start < 0 || end >= arr.size()) return 0;

    int first = findFirst(arr, element, start, end);
    
    // If the element isn't found at all, return 0
    if (first == -1) return 0;

    int last = findLast(arr, element, start, end);

    return (last - first) + 1;
}
    
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto i:queries)
        {
            ans.push_back(binaryCount(arr,i[2], i[0], i[1]));
        }
        return ans;
    }
};