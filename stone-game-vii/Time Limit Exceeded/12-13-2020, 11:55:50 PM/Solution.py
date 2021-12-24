// https://leetcode.com/problems/stone-game-vii

class Solution:
    def stoneGameVII(self, stones: List[int]) -> int:
        sys.setrecursionlimit(int(1e8))
        
        pf = stones
        n = len(stones)
        for i in range(1,n):
            pf[i] += pf[i-1]
            
        def sum(i,j) ->int :
            s =  pf[j]
            if(i > 0):
                s -= pf[i-1]
            return s
        
        @cache
        def solve(i,j) -> int:
            if i == j:
                return 0
            l = i
            r = n-j-1
            t = (l+r+1)%2
            if t == 1:
                return max(sum(i+1,j)+solve(i+1,j),sum(i,j-1)+solve(i,j-1))
            else :
                return min(-sum(i+1,j)+solve(i+1,j),-sum(i,j-1)+solve(i,j-1))
            
        
        ans = solve(0,n-1)
        return ans
            
            