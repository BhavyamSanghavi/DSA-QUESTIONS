class Solution:
    def reverseByType(self, s: str) -> str:
        result = []
        result_2 = []
        list_s1 = list(s)
        for i in range (len(list_s1)):
            if list_s1[i] in ")(*&^%$#@!":
                list_s1[i]=-1
            else :    
               result.append(list_s1[i])
        result.reverse()
        #return result
        list_s = list(s)
        for i in range (len(list_s)):
            if list_s[i]  in ")(*&^%$#@!":
                list_s[i]=list_s[i]
                result_2.append(list_s[i])
            else : 
                list_s[i] = -1
                #result_2.append(list_s[i])
        #result_2.append(list_s[i])
        result_2.reverse()
        j=0
        for i in range (len(s)):
            if s[i]  in ")(*&^%$#@!":
                list_s[i]=result_2[j]
                j+=1
        j=0
        for i in range (len(s)):
            if s[i]  not in ")(*&^%$#@!":
                list_s[i]=result[j]
                j+=1        

        return ''.join(list_s)

        
                
                
        