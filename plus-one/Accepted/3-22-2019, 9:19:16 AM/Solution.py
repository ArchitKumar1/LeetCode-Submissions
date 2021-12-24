// https://leetcode.com/problems/plus-one

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        digits = map(str,digits)
        digits=list(str(int(''.join(digits))+1))
        digits =[ int(i) for i in digits]
        return digits