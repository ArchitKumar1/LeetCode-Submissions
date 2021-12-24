// https://leetcode.com/problems/count-special-quadruplets

class Solution:
    def countQuadruplets(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        for i in range(0,n):
            for j in range(i+1,n):
                for k in range(j+1,n):
                    for l in range(k+1,n):
                        if nums[i] +  nums[j] + nums[k] == nums[l]: ans+=1
        return ans