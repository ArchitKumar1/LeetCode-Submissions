// https://leetcode.com/problems/burst-balloons

class Solution:
    def maxCoins(self, candies: List[int]) -> int:
        candies = [1,*candies,1]
        @cache
        def comp(i,j):
            ans = 0
            for k in range(i+1,j):
                ans = max(ans,(candies[i] * candies[k] * candies[j]) +  comp(i,k) + comp(k,j))
            return ans
        return comp(0,len(candies)-1)