// https://leetcode.com/problems/distinct-echo-substrings

class Solution:
    def distinctEchoSubstrings(self, s: str) -> int:
        return len({s[i:j] for j in range(len(s)) for i in range(j) if s[i:j] == s[j:j+j-i]})