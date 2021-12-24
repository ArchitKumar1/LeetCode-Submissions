// https://leetcode.com/problems/maximum-swap

class Solution:
    def maximumSwap(self, num: int) -> int:
        maxn = num
        s = list(str(num))
        l = len(s)
        for i in range(0,l):
            for j in range(i+1,l):
                a = s[i]
                b = s[j]
                s[i] = b
                s[j] = a
                maxn = max(int(''.join(s)),maxn)
        return maxn