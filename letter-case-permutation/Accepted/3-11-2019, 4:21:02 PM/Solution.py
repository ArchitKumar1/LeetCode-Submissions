// https://leetcode.com/problems/letter-case-permutation

class Solution(object):
    def letterCasePermutation(self, S):
        return list(set(map(''.join, itertools.product(*((c.upper(), c.lower()) for c in S)))))
        