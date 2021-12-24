// https://leetcode.com/problems/4sum

class Solution:
    def fourSum(self, nums: List[int], t: int) -> List[List[int]]:
        n = len(nums)
        s = set()
        vis = defaultdict(lambda : [])
        
        s = set()
        for i in range(n):
            for j in range(i+1,n):
                l = t - nums[i]-nums[j]
                for x,y in vis[l]:
                    ans = tuple(sorted([x,y,nums[i],nums[j]]))
                    s.add(ans)
                    
                    
            
            for j in range(0,i):
                l = nums[j] + nums[i]
                vis[l].append([nums[j] ,nums[i]])    
                
        return list(s)
                
                