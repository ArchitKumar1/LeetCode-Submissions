// https://leetcode.com/problems/sort-an-array

class Solution:
    def quicksort(self, nums):
        if len(nums) <= 1:
            return nums

        pivot = random.choice(nums)
        lt = [v for v in nums if v < pivot]
        eq = [v for v in nums if v == pivot]
        gt = [v for v in nums if v > pivot]

        return self.quicksort(lt) + eq + self.quicksort(gt)
