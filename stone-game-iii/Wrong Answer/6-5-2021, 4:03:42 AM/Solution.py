// https://leetcode.com/problems/stone-game-iii

class Solution:
    def stoneGameIII(self, stones: List[int]) -> str:
        n = len(stones)
        @cache
        def dp(i,t):
            if i == n : return 0
            
            if t == 0:
                ans = -int(1e9)
                s = 0
                for j in [i,i+1,i+2]:
                    if j < n:
                        s += stones[j]
                        ans = max(ans,s + dp(j+1,t^1))
                return ans
            else:
                ans = int(1e9)
                s = 0
                for j in [i,i+1,i+2]:
                    if j < n:
                        s += stones[j]
                        ans = min(ans,s + dp(j+1,t^1))
                return -ans
            
        ans = dp(0,0)
        print(ans)
        if ans > 0 : return "Alice"
        if ans < 0 : return "Bob"
        if ans == 0: return "Tie"