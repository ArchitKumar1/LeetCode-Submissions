// https://leetcode.com/problems/valid-palindrome

class Solution:
    def isPalindrome(self, s: 'str') -> 'bool':
        a=''
        for x in s:
            if(x.isalpha()):
                a+=(str.lower(x))
        return a==a[::-1]