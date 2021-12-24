// https://leetcode.com/problems/additive-number

class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        n = len(num)
        
        @cache
        def dp(i,val):
            if i>=n: return True
            for j in range(i,n):
                v = int(num[i:j+1])
                if v > val and dp(j+1,v) is True:
                    return True
            return False
    
        return dp(0,0)
    