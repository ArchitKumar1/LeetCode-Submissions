// https://leetcode.com/problems/burst-balloons

class Solution:
    def maxCoins(self, candies: List[int]) -> int:
        n = len(candies)
        @cache
        def comp(i,j):
            ans = 0
            for k in range(i,j+1):
                l = 1 if i == 0 else candies[i-1]
                r = 1 if j == n-1 else candies[j+1]
                ans = max(ans,(l * candies[k] * r) 
                + (0 if k == i else comp(i,k-1))
                + (0 if k == j else comp(k+1,j)))
            return ans
        return comp(0,len(candies)-1)