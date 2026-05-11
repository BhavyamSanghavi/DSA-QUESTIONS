1class Solution(object):
2    def isPerfectSquare(self, num):
3        n=sqrt(num)
4        n=int(n)
5        return n*n==num
6        