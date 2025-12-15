1def countVowel(s):
2    vowelSet = {'a', 'e', 'i', 'o', 'u'}
3    vowelCount = 0
4    for char in s.lower():
5        if char in vowelSet:
6            vowelCount += 1
7    return vowelCount
8
9def reverseString(word):
10    return word[::-1]
11
12class Solution(object):
13    
14    def reverseWords(self, string):
15        words = string.split()
16        if not words:
17            return ""
18        
19        first_word = words[0]
20        vowel_count_target = countVowel(first_word)
21        
22        for i in range(1, len(words)):
23            current_word = words[i]
24        
25            if vowel_count_target == countVowel(current_word):
26                words[i] = reverseString(current_word)
27        
28        return " ".join(words)