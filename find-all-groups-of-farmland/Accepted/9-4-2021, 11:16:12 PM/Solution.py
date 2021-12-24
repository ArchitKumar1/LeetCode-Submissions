// https://leetcode.com/problems/find-all-groups-of-farmland

class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        n = len(land)
        m = len(land[0])
        
        def update(i,j,I,J):
            for x in range(i,I+1):
                for y in range(j,J+1):
                    land[x][y] = 0
                    
        ans = []
        for i in range(n):
            for j in range(m):
                if land[i][j] == 0: continue
                I,J = i,j
                while I+1 < n and land[I+1][J] == 1:
                    I+= 1
                while J+1 < m and land[I][J+1] == 1:
                    J+= 1
                ans.append([i,j,I,J])
                update(i,j,I,J)
                
        return ans
                