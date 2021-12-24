// https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate

class Solution:
    def nearestValidPoint(self, x: int, y: int, points: List[List[int]]) -> int:
        
        d = float("inf")
        ans = -1
        
        dist = lambda x1,y1 : abs(x1-x) + abs(y1-y)
        
        for i,p in enumerate(points):
            dis = dist(p[0],p[1])
            if dis < d:
                d = dis
                ans = i
        return ans
            