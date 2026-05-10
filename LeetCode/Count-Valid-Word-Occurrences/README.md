# Count Valid Word Occurrences

Can you solve this real interview question? Count Valid Word Occurrences - You are given an array of strings chunks. The strings are concatenated in order to form a single string s.

You are also given an array of strings queries.

A word is defined as a substring of s that:

 * consists of lowercase English letters ('a' to 'z'),
 * may include hyphens ('-') only if each hyphen is surrounded by lowercase English letters, and
 * is not part of a longer substring that also satisfies the above conditions.

Any character that is not a lowercase English letter or a valid hyphen acts as a separator.

Return an integer array ans such that ans[i] is the number of occurrences of queries[i] as a word in s.

A substring is a contiguous non-empty sequence of characters within a string.

 

Example 1:

Input: chunks = ["hello wor","ld hello"], queries = ["hello","world","wor"]

Output: [2,1,0]

Explanation:

 * Concatenating all strings in chunks gives s = "hello world hello".
 * The valid words in s are "hello" which appears twice and "world" which appears once.
 * Thus, the ans = [2, 1, 0].

Example 2:

Input: chunks = ["a--b a-","-c"], queries = ["a","b","c"]

Output: [2,1,1]

Explanation:

 * Concatenating all strings in chunks gives s = "a--b a--c".
 * The valid words in s are "a" which appears twice, "b" which appears once, and "c" which appears once.
 * Thus, the ans = [2, 1, 1].

Example 3:

Input: chunks = ["hello"], queries = ["hello","ell"]

Output: [1,0]

Explanation:

 * The valid word in s is "hello" which appears once.
 * Thus, the ans = [1, 0].