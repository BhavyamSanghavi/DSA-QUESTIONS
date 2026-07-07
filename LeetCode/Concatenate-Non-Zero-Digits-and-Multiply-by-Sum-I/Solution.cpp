1class Solution(object):
2    def sumAndMultiply(self, n):
3        """
4        :type n: int
5        :rtype: int
6        """
7        n=str(n)
8        num=""
9        sum=0
10        for i in n:
11            if i!='0':
12                num+=i
13                sum+=int(i)     
14        if(num==""):
15           num=0
16        return sum*int(num)