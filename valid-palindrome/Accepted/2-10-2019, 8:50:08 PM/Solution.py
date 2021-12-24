// https://leetcode.com/problems/valid-palindrome

class Solution:
    def isPalindrome(self, s: 'str') -> 'bool':
        a=''
        for x in s:
            if(x.isalpha() or x.isdigit()):
                a+=(str.lower(x))
        return a==a[::-1]