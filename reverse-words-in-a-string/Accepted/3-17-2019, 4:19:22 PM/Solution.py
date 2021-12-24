// https://leetcode.com/problems/reverse-words-in-a-string

class Solution:
    
    def reverseWords(self, s: str) -> str:
        s = s.split();
        s.reverse();
        a = ' '.join(s)
        return a
   