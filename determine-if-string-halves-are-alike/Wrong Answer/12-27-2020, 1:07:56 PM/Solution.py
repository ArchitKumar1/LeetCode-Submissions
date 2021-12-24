// https://leetcode.com/problems/determine-if-string-halves-are-alike

class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        t = "aeiouAEIOU"
        n = len(s)
        safe = False
        
        a = 0;
        for x in s[0:n//2]:
            for c in t:
                if(x == c):
                    a+= 1
        for x in s[n//2]:
            for c in t:
                if(x == c):
                    a-= 1
            
        return a ==0
        