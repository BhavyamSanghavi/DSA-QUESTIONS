#User function Template for python3

class Solution:
    def evenlyDivides(self, n):
        ans=0
        num=str(n)
        for i in num:
            i=int(i)
            if i!=0 and n%i==0:
                ans+=1
        return ans