// https://leetcode.com/problems/numbers-with-repeated-digits

class Solution:
    def numDupDigitsAtMostN(self, N: int) -> int:
        a = [[list(str(x)),set(list(str(x)))] for x  in range(1,N+1)]
        cnt = 0
        for i in range(0,N):
            if(len(a[i][0])!= len(a[i][1])):
                cnt+=1
        return cnt