// https://leetcode.com/problems/bitwise-ors-of-subarrays

class Solution:
    def subarrayBitwiseORs(self, A):
        nums, n, pre = set(), len(A), set()
        for i in range(n):
            new = {A[i]}
            for num in pre:
                new |= {num|A[i]}
            pre = new
            nums |= pre
        return len(nums)