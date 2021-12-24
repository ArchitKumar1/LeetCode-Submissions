// https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths

class Solution:
    
    
    class dsu:
        def __init__(self,n):
            self.par = [i for i in range(n)]
        
        def find(self,x):
            if(self.par[x] == x):
                return x
            else:
                self.par[x] = self.find(self.par[x])
                return self.par[x]
            
        def merge(self,x,y):
            x,y = self.find(x),self.find(y)
            if(x != y):
                self.par[y] = x;
        
            
    def distanceLimitedPathsExist(self, n: int, edgeList: List[List[int]], queries: List[List[int]]) -> List[bool]:
        edgeList.sort(key =lambda x : x[2])
        for i,q in enumerate(queries):
            q.append(i)
            
        queries.sort(key =lambda x : x[2])
        
        ans = [False]*len(queries)
        
        D1 =  self.dsu(10000)
        
        i=0
        for u,v,L,idx in queries:
            while(i < len(edgeList) and edgeList[i][2] < L):
                D1.merge(edgeList[i][0],edgeList[i][1])
                i+= 1
            if(D1.find(u) == D1.find(v)):
                ans[idx] = True
        return ans
                