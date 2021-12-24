// https://leetcode.com/problems/check-if-the-sentence-is-pangram

class Solution:
    def checkIfPangram(self, s: str) -> bool:
        x = len(set(list(s)))
        if x == 26:
            return True
        else:
            return False