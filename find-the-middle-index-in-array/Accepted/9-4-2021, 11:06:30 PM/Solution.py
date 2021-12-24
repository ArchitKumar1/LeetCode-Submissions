// https://leetcode.com/problems/find-the-middle-index-in-array

class Solution:
    def findMiddleIndex(self, nums: List[int]) -> int:
        ans = 1e9
        nums = [0,*nums,0]
        for i in range(1,len(nums)-1):
            l = sum(nums[0:i])
            r = sum(nums) - l - nums[i]
            if l == r and i < ans:
                ans = i
                
        if ans == 1e9:
            return -1
        return ans-1