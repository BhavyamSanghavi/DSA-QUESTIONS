#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3

class Solution:
    def insertInterval(self, intervels, new):
        intervels.append(new)
        intervels.sort(key=lambda x:x[0])
        l=[intervels[0]]
        for k in  intervels[1:]:
            if k[0]>l[-1][1]:
                l.append(k)
                continue
            l[-1][1]=max(l[-1][1],k[1])
        return l

#{ 
 # Driver Code Starts.
if __name__ == '__main__': 
    t = int(input ())
    for _ in range (t):
        N = int(input())
        intervals = [list(map(int, input().split())) for i in range(N)]
        newEvent = list(map(int, input().split()))
        ob = Solution()
        res = ob.insertInterval(intervals, newEvent)
        print('[', end = '')
        for i in range(len(res)):
            print('[', end = '')
            print(str(res[i][0])+','+str(res[i][1]), end = '')
            print(']', end = '')
            if i < len(res)-1:
                print(',', end='')
        print(']')
        print("~")
# } Driver Code Ends