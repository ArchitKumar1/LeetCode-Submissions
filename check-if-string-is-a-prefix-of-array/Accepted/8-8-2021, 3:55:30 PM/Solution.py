// https://leetcode.com/problems/check-if-string-is-a-prefix-of-array

class Solution:
    def isPrefixString(self, s: str, words: List[str]) -> bool:
        
        t = ""
        for w in words: 
            t += w
            if s == t:
                return True
        return False