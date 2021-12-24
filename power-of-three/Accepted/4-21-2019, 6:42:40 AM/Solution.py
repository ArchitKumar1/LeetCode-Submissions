// https://leetcode.com/problems/power-of-three

class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        while(n > 3) : n = n / 3
        return  n == 1 or n == 3