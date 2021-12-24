// https://leetcode.com/problems/numbers-with-repeated-digits

class Solution:
    def numDupDigitsAtMostN(self, N: int) -> int:
        a = [[i for i in str(x)] for x  in range(1,N+1)]
        b = [set(x) for x in a]
        cnt = 0
        for i in range(0,N):
            if(len(a[i])!= len(b[i])):
                cnt+=1
        return cnt