// https://leetcode.com/problems/number-complement

class Solution:
    def findComplement(self, num: int) -> int:
        return num ^ (2 ** (len(bin(num)) - 2) - 1)