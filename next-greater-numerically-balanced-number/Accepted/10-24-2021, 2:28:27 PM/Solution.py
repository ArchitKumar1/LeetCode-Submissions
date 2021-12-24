// https://leetcode.com/problems/next-greater-numerically-balanced-number

class Solution:
    def nextBeautifulNumber(self, n: int) -> int:
        ans = 0
        m = n
        while True:
            m += 1
            cnt = collections.Counter(list(str(m)))
            safe = True
            for k,v in cnt.items():
                if(int(k) != v): safe = False
                    
            if safe: return m
            