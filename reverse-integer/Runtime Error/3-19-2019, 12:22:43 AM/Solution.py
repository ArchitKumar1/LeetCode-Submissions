// https://leetcode.com/problems/reverse-integer

class Solution:
    def reverse(self, x):
        s = cmp(x, 0)
        r = int(s*x[::-1])
        return s*r * (r < 2**31)