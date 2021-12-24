// https://leetcode.com/problems/sign-of-the-product-of-an-array

class Solution:
    def arraySign(self, nums: List[int]) -> int:
        x = functools.reduce(lambda a,b : a*b,nums)
        
        if(x > 0):
            return 1
        if(x < 0):
            return -1
        if(x == 0):
            return 0
        