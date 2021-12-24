// https://leetcode.com/problems/two-out-of-three

class Solution:
    def twoOutOfThree(self, nums1: List[int], nums2: List[int], nums3: List[int]) -> List[int]:
        nums1 = list(set(nums1))
        nums2 = list(set(nums2))
        nums3 = list(set(nums3))
        
        vis = defaultdict(lambda: 0)
        for x in nums1:
            vis[x]+= 1
        for x in nums2:
            vis[x]+= 1
        for x in nums3:
            vis[x]+= 1
            
        ans = []
        for k,v in vis.items():
            if v >= 2:
                ans.append(k)
        return ans
                
            
