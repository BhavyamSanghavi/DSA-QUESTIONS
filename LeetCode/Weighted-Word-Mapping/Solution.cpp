class Solution:
    def mapWordWeights(self, words: List[str], weights: List[int]) -> str:
        h_map = {}
        lett_str = ['abcdefghijklmnopqrstuvwxyz']
        lett = list(*lett_str)
        for i in range(len(lett)):
           h_map[lett[i]] = weights[i]
        #for i in range(len(weights))
        temp = []
        temp_value=0
        for word in words:
            temp_value=0
            for letter in word:
                temp_value = temp_value + h_map[letter]
            temp.append(temp_value%26)

        #return temp
        lett_str2 = ['zyxwvutsrqponmlkjihgfedcba']
        lett2 = list(*lett_str2)
        result = []
        for l in range(len(temp)):
             result.append(lett2[temp[l]])

        #return result
        return ''.join(result)
         #   h_map()
        