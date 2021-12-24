// https://leetcode.com/problems/reverse-integer

class Solution:
    def reverse(self, x: int) -> int:
        cnt = 0
        s = str(x)
        if(x < 0):
            cnt+=1
            s = s[1:len(s)]
        s = s[::-1]
        ans = int(s)
        if(cnt == 1):
            ans*=-1
        return ans