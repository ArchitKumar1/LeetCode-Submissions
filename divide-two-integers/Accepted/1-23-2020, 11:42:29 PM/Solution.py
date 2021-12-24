// https://leetcode.com/problems/divide-two-integers

class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        toggle = -1 if (divisor > 0 and dividend < 0) or (divisor < 0 and dividend > 0) else 1
        dividend, divisor = abs(dividend), abs(divisor)
        q, times = 0, 0
        while dividend >= divisor:
            temp = dividend - (divisor << times)
            if temp >= 0:
                q += (1 << times)
                times += 1
                dividend = temp
            else:
                times -= 1
        return max(-2147483648, min(q * toggle, 2147483647))