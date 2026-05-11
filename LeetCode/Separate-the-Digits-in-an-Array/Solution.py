1class Solution(object):
2    def separateDigits(self, nums):
3        ans=[]
4        for i in nums:
5            n=str(i)
6            for j in n:
7                ans.append(int(j))
8        
9        return ans
10        