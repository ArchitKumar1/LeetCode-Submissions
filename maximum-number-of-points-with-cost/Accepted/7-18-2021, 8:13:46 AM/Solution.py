// https://leetcode.com/problems/maximum-number-of-points-with-cost

class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        dp = points[0]
        INF = float(-inf)
        
        for i in range(1, len(points)):
            newdp = [INF] * len(points[i])
            
            # Taking left side
            left = INF
            for j in range(len(points[i])):
                left = max(left, dp[j])
                newdp[j] = max(newdp[j], left + points[i][j])
                left -= 1
                
            # Taking right side
            right = INF
            
            for j in range(len(points[i]) - 1, -1, -1):
                right = max(right, dp[j])
                newdp[j] = max(newdp[j], right + points[i][j])
                right -= 1
                
            dp = newdp
        return max(dp)