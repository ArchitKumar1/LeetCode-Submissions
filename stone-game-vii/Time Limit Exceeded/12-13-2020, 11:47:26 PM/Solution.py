// https://leetcode.com/problems/stone-game-vii

class Solution:
    def stoneGameVII(self, stones: List[int]) -> int:
        
        pf = stones
        n = len(stones)
        for i in range(1,n):
            pf[i] += pf[i-1]
            
        def sum(i,j):
            s =  pf[j]
            if(i > 0):
                s -= pf[i-1]
            return s
        
        @lru_cache(maxsize = None)
        def solve(i,j,t):
            if i == j:
                return 0
            if t == 1:
                return max(sum(i+1,j)+solve(i+1,j,t^1),sum(i,j-1)+solve(i,j-1,t^1))
            else :
                return min(-sum(i+1,j)+solve(i+1,j,t^1),-sum(i,j-1)+solve(i,j-1,t^1))
            
        return solve(0,n-1,1)
            
            