#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends

#User function Template for python3
class Solution:
    def longestSubarray(self, arr, k):
        prefix_diffs, diff, max_length = {0: -1}, 0, 0
        for i in range(len(arr)):
            diff += 1 if arr[i] > k else -1
            if diff > 0:
                max_length = i + 1
            elif diff - 1 in prefix_diffs:
                max_length = max(max_length, i - prefix_diffs[diff - 1])
            if diff not in prefix_diffs:
                prefix_diffs[diff] = i
        return max_length


#{ 
 # Driver Code Starts.

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        
        arr = [int(x) for x in input().strip().split()]
        k = int(input())
        
        ob = Solution()
        print(ob.longestSubarray(arr, k))
        print("~")
        t -= 1
# } Driver Code Ends