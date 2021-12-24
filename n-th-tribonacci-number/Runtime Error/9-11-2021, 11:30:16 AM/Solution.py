// https://leetcode.com/problems/n-th-tribonacci-number

class Solution:
    @cache
    def tribonacci(self, n: int) -> int:
        if n <= 1: return n
        if n == 2: return 1
        return self.fib(n-1) +self.fib(n-2) + self.fib(n-3)