// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies

class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        mx = max(candies)
        return [ (x + extraCandies) >= mx for x in candies]
    