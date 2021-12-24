// https://leetcode.com/problems/additive-number

class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        n = len(num)
        
        @cache
        def dp(i,val,cnt):
            if i>=n: return (cnt >= 3)
            for j in range(i,n):
                v = int(num[i:j+1])
                print(v)
                if v > val and dp(j+1,v,cnt+1) is True:
                    return True
            return False
    
        return dp(0,0,0)
    