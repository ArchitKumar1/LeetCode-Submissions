// https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values

class Solution:
    def splitString(self, s: str) -> bool:
        
        n = len(s)
        
        @cache
        def solve(i,val,p):
            # print(i,val,p)
            if(i == n):
                if( p > 1):
                    return True
                else:
                    return False
            
            ans = False
            
            for j in range(i,n):
                x = s[i:j+1]
                y = int(x)
                # print(i,x,s,y,val)
                if( val == -1 or y == (val-1)):
                    if(solve(j+1,y,p+1) == True):
                        # print("in",i,x,s,y,val)
                        ans = True
                        
            return ans
        
        return solve(0,-1,0)
                
                
        
        
                