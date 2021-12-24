// https://leetcode.com/problems/longest-happy-prefix

class Solution:
    def longestPrefix(self, s: str) -> str:
        res = ''
        for i in range(1, len(s)):
            if s[:i] == s[-i:]:
                res = s[:i]
        return res