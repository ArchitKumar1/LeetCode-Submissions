// https://leetcode.com/problems/fibonacci-number

class Solution:
    
    @cache
    def fib(self, n: int) -> int:
        if n <= 1: return n
        return fib(self,n-1) + fib(self,n-2)