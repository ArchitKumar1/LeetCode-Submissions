// https://leetcode.com/problems/happy-number

class Solution:
    
    def isHappy(self, n: int) -> bool:
        x = n
        for i in range(0,100):
            s = str(x);
            y = 0
            for i in s:
                y += int(i)**2
            x = str(y)
            if(x == '1'):
                return 1
        return 0

        