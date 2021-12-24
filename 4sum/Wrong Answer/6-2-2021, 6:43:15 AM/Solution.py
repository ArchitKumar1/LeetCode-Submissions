// https://leetcode.com/problems/4sum

class Solution:
    def fourSum(self, nums: List[int], t: int) -> List[List[int]]:
        n = len(nums)
        
        s = set()
        vis = defaultdict(lambda : [])
        
        for i in range(n):
            for j in range(i+1,n):
                l = t - nums[i]-nums[j]
                for x,y in vis[l]:
                    s.add((x,y,nums[i],nums[j]))
                    
            
            for j in range(0,i):
                l = nums[j] + nums[i]
                vis[l].append([nums[j] ,nums[i]])    
                
        res = [list(x) for x in s]
        return res
                
                