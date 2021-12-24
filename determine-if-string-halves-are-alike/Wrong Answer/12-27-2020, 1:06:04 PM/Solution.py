// https://leetcode.com/problems/determine-if-string-halves-are-alike

class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        s = s.lower()
        t = "aeiou"
        n = len(s)
        safe = False
        for c in t:
            print(s[0:n//2].count(c),s[n//2:].count(c))
            if( s[0:n//2].count(c) != s[n//2:].count(c)):
                safe = True
            
        return 0 if safe == True else 1
        