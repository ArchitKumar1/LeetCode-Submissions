// https://leetcode.com/problems/power-of-four

class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        while(n > 4)  : n = n / 4
        return n == 4 or n == 1