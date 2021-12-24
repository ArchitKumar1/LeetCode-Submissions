// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number

class Solution(object):
    def smallerNumbersThanCurrent(self, nums):
        return [sum([1 if i > j else 0 for j in nums]) for i in nums]
        