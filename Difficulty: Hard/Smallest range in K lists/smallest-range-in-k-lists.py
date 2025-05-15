
import heapq

class Solution:
    def findSmallestRange(self, arr):
        k = len(arr)
        n = len(arr[0])
        
        min_heap = []
        current_max = float('-inf')
        
        # Initialize the heap with the first element from each list
        for row in range(k):
            val = arr[row][0]
            heapq.heappush(min_heap, (val, row, 0))
            current_max = max(current_max, val)
        
        best_range = [float('-inf'), float('inf')]

        while True:
            current_min, row, col = heapq.heappop(min_heap)
            
            # Update the best range if the current one is smaller
            if current_max - current_min < best_range[1] - best_range[0]:
                best_range = [current_min, current_max]
            
            # If we've reached the end of one list, stop
            if col + 1 == len(arr[row]):
                break
            
            # Push the next element from the same list
            next_val = arr[row][col + 1]
            heapq.heappush(min_heap, (next_val, row, col + 1))
            current_max = max(current_max, next_val)
        
        return best_range
        


#{ 
 # Driver Code Starts
# Initial Template for Python 3

t = int(input())
for _ in range(t):
    n = int(input())
    k = int(input())
    arr = []
    for _ in range(k):
        arr.append(list(map(int, input().strip().split())))
    r = Solution().findSmallestRange(arr)
    print(r[0], r[1])
    print("~")

# } Driver Code Ends