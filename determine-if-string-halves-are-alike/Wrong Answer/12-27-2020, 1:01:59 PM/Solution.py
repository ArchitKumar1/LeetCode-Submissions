// https://leetcode.com/problems/determine-if-string-halves-are-alike

class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        s = s.upper()
        t = "aeiou"
        n = len(s)
        safe = True 
        for c in t:
            safe = s[0:n//2].count(c) == s[n//2:].count(c)
            
        return 1 if safe == True else 0
        