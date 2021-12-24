// https://leetcode.com/problems/minimum-total-space-wasted-with-k-resizing-operations

class Solution:
    def minSpaceWastedKResizing(self, nums: List[int], K: int) -> int:
        n = len(nums)
        
        @cache
        def comp(i,p,k):
            if i == n: return 0
            ans = 0
            if(nums[p] >= nums[i]):
                a1,a2 = int(1e9),int(1e9)
                if(k > 0): a1 = comp(i+1,i,k-1)
                a2 = nums[p] - nums[i] + comp(i+1,p,k)
                return min(a1,a2)
            else:
                # have to resize
                if k > 0 :
                    return comp(i+1,i,k-1);
                else: return int(1e9)
        fans = int(1e9)                   
        for i in range(0,n):
            comp.cache_clear()
            fans = min(fans,comp(0,i,K))

        return fans