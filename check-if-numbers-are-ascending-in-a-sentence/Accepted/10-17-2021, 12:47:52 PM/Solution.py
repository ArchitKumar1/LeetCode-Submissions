// https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence

class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        s = s.split()        
        a = [ int(c) for c in s if c.isnumeric()]
        return a == sorted(a) and len(a) == len(list(set(a)))