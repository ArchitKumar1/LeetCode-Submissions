// https://leetcode.com/problems/factorial-trailing-zeroes

class Solution(object):
    def trailingZeroes(self, n):
        x=5
        sum=0
        while(n>=x):
            sum+=n/x
            x=x*5
        return sum
        