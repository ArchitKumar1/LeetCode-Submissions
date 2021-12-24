// https://leetcode.com/problems/squares-of-a-sorted-array

class Solution:
    def sortedSquares(self, A):
        A=[x**2 for x in A]
        A=sorted(A)
        return A
        