// https://leetcode.com/problems/length-of-last-word

class Solution:
    def lengthOfLastWord(self, s: 'str') -> 'int':
        s = s.strip().split()
        l = len(s)
        a = s[l-1]
        return len(a)