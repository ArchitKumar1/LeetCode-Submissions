// https://leetcode.com/problems/advantage-shuffle

class Solution:
    def advantageCount(self, nums2: List[int], nums1: List[int]) -> List[int]:
        n,m = len(nums1),len(nums2)
        
        a = [(nums1[i],i) for i in range(n)]
        a.sort(key = lambda x : x[0])
        nums2.sort()
        i = 0
        res = [-1]*m
        
        print(a,nums2)
        for j in range(n):
            if a[i][0] < nums2[j]:
                res[a[i][1]] = nums2[j]
                i+= 1
            
        print(res)
        for k in range(m):
            if res[k] == -1:
                res[k] = nums2[i]
                i+= 1
        return res
            