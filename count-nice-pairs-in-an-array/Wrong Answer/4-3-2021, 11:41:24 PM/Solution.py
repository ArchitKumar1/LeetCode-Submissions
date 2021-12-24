// https://leetcode.com/problems/count-nice-pairs-in-an-array

class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        M = int(1e9+7)
        arr = collections.defaultdict(lambda x : 0)
        rev  = lambda y: int(str(y)[::-1])
        ans = 0
        for x in nums:
            val = x - rev(x)
            print(x,rev(x),val)
            if val in arr:
                print(val,arr[val])
                ans += arr[val]
                arr[val] = arr[val]+1;
            arr[val] = 1
            
        return ans % M
            
            