// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule

class Solution:
    def minDifficulty(self, jobs: List[int], d: int) -> int:
        
        n = len(jobs)
        @cache
        def dp(i,c):
            if i == n:
                return 0 if c == d else 1e9
            ans = int(1e9)
            mx = 0
            for j in range(i,n):
                mx = max(mx,jobs[i])
                ans = min(ans, mx + dp(j+1,c+1))
            return ans
        ans = dp(0,0)
        
        return ans if ans!=int(1e9) else -1
            