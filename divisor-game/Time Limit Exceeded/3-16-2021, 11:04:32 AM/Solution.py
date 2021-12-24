// https://leetcode.com/problems/divisor-game

class Solution:
    def divisorGame(self, N: int) -> bool:
        
        
        def solve(n):
            ans = False
            for i in range(1,n):
                if n%i == 0:
                    if not solve(n - i) is True:
                        ans = True
            return ans
        
        return solve(N)
                    