#{ 
 # Driver Code Starts

# } Driver Code Ends
class Solution:
    def rearrange(self, arr):
        ans=[-1]*len(arr)
        for i in range(0,len(arr)):
            if arr[i]!=-1:
                ans[arr[i]]=arr[i]
            
        return ans

#{ 
 # Driver Code Starts.
def main():
    t = int(input())
    for _ in range(t):
        input_str = input()
        arr = list(map(int, input_str.split()))
        solution = Solution()
        ans = solution.rearrange(arr)
        print(" ".join(map(str, ans)))

if __name__ == "__main__":
    main()
# } Driver Code Ends