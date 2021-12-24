// https://leetcode.com/problems/finding-the-users-active-minutes

class Solution:
    def findingUsersActiveMinutes(self, logs: List[List[int]], k: int) -> List[int]:
        x = collections.defaultdict(lambda : set())
        for a,b in logs:
            x[a].add(b)
            
        
        res = [0]*(k)
        
        for v in x.values():
            res[len(v)-1]+=1
        
        return res