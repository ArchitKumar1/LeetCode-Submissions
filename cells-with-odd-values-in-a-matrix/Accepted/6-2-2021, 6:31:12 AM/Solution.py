// https://leetcode.com/problems/cells-with-odd-values-in-a-matrix

class Solution:
    def oddCells(self, m: int, n: int, indices: List[List[int]]) -> int:
        r = [0]*m
        c = [0]*n
        
        for i,j in indices:
            r[i]+=1
            c[j]+=1
                
        ans = 0
        for i in range(m):
            for j in range(n):
                rsum = r[i] + c[j]
                if rsum%2 == 1:
                    ans+=1
                    
        return ans