// https://leetcode.com/problems/maximum-students-taking-exam

class Solution:
    def maxStudents(self, seats: List[List[str]]) -> int:
        bins = list(map(lambda a : reduce(lambda x,y : x<<1 | (y=='.'), a, 0), seats))   
        @lru_cache(None)
        def dp(i,mask):
            if i == len(seats): return 0
            return max(bin(curr).count('1') + dp(i+1,curr)   
                        for curr in range(1 << len(seats[0])) 
                            if (  (curr | bins[i] == bins[i]) and 
                                (curr | mask) & ((curr | mask) >> 1) == 0  ) )
        return dp(0,0)