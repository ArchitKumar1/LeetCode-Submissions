// https://leetcode.com/problems/count-nice-pairs-in-an-array

class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        M = int(1e9+7)
        arr = collections.defaultdict(lambda : 0)
        rev  = lambda y: int(str(y)[::-1])
        ans = 0
        for x in nums:
            val = x - rev(x)
            ans += arr[val]
            arr[val]+=1
            
        return ans % M
            
            