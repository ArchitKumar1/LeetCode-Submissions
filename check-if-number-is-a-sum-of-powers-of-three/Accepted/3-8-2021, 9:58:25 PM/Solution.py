// https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three

class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        for i in range(20,-1,-1):
            
            p = int(pow(3,i))
            if(n >= p):
                n-=p
        if n == 0:
            return True
        return False