class Solution:
    def trimTrailingVowels(self, s: str) -> str:
        result = []
        vowels = ['a','e','i','o','u']
        result = list(s)
        n=len(result)
        last_pointer=0
        #temp = 
        for i in range(len(result)):
            if result[n -1 - i] not in vowels:
                return s[0:n - i]

        return ''

       
        