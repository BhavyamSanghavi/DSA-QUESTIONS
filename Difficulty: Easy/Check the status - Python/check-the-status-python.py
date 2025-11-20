class Solution:
    def checkStatus(self, a, b, flag):
        if ((a>0 and b<0) or (b>0 and a<0)) and flag==False:
            return True
        if(a<0 and b<0) and flag==True:
            return True
        return False