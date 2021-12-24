// https://leetcode.com/problems/valid-palindrome

class Solution:
    def isPalindrome(self, s: 'str') -> 'bool':
        a=''.join([x.lower() for x in s if x.isalnum()])
        return a==a[::-1]