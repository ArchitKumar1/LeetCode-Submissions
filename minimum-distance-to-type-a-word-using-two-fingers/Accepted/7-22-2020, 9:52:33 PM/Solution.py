// https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers

import functools
class Solution:
    
    def dist(self,x,y):
        if(y == -1):
            return 0
        return abs(x//6 - y//6) + abs(x%6 - y%6)
    
    @functools.lru_cache(None)
    def solve(self,i,x,y) -> int:
        if(i == self.n):
            return 0
        ans = 1e9
        curr = ord(self.word[i]) -ord('A')
        ans = min(ans, self.dist(curr,x)+ self.solve(i+1,curr,y))
        ans = min(ans, self.dist(curr,y)+ self.solve(i+1,x,curr))
        return ans
                  
    def minimumDistance(self, word: str) -> int:
        self.word = word
        self.n = len(word)
        return self.solve(0,-1,-1)
        
        
        