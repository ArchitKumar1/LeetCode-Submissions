// https://leetcode.com/problems/fibonacci-number

class Solution:
    
    #cache
    def fib(self, n: int) -> int:
        if n <= 1: return n
        return fib(n-1) + fib(n-2)