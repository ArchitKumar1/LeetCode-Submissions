// https://leetcode.com/problems/maximum-ice-cream-bars

class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()
        ans = 0
        pos = 0
        while coins > 0 and pos < len(costs):
            if costs[pos] <= coins:
                coins -= costs[pos]
                ans +=1
                pos += 1
            else:
                break
        return ans