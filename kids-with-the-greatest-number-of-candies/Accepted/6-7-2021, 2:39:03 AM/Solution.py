// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies

class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        return [ (x + extraCandies) >= max(candies) for x in candies]
    