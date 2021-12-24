// https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square

class Solution:
    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
        ml = max([min(r[0],r[1]) for r in rectangles])
        
        return sum([1 if min(r[0],r[1]) == ml else 0 for r in rectangles])