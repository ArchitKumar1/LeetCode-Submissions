// https://leetcode.com/problems/frog-position-after-t-seconds

from collections import defaultdict
class Solution:
    def frogPosition(self, n: int, edges: List[List[int]], T: int, target: int) -> float:
        G = defaultdict(list)
        
        for u,v in edges:
            G[u].append(v)
            G[v].append(u)
        ans = []
        vis = set()
        def dfs(u,prob,t):
            print(u,prob,t)
            if(t == T and u == target):
                ans.append(prob)
            
            vis.add(u)
            count = len(G[u])
            child = 0
            for v in G[u]:
                if v in vis:
                    continue
                G[v].remove(u)
                dfs(v,prob/count,t+1)
                child+=1
                
            if target == u and child == 0 and t <= T:
                ans.append(prob)
            
        dfs(1,1.0,0)
        return ans[0]
                    