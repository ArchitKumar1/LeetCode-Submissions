// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced

class Solution:
    def minSwaps(self, s: str) -> int:
        cnt = 0
        ans = 0
        for c in s:
            if c == '[':
                cnt += 1
            else:
                cnt -= 1
            if(cnt < 0):
                ans += 1
                cnt += 2
        return ans
                