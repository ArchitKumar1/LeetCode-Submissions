// https://leetcode.com/problems/maximum-number-of-words-you-can-type

class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        words = text.split()
        
        ans = 0
        
        b = set(brokenLetters)
        for w in words: 
            safe = True
            for c in w : 
                if c in b:
                    safe = False
                    
            if safe: 
                ans += 1
        return ans