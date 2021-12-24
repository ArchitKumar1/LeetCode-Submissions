// https://leetcode.com/problems/perfect-number

import math
class Solution(object):
    def checkPerfectNumber(self, num):
        sum=1
        for i in range(2,int(math.sqrt(num))+1):
            if(num%i == 0 ):
                sum=sum+i+(num/i)
            # else:
            #     sum=sum+i
        
        if(sum==num):
            return True
        else:
            return False
        