// https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary

class Solution:
    def numWays(self, words: List[str], target: str) -> int:
        cnt = defaultdict(int)
        for w in words:
            for i,c in enumerate(w):
                cnt[(i,c)]+=1
        n = len(target)
        m = max([len(w) for w in words])
        M = 10 ** 9 + 7
        @cache    
        def dp(i,j):
            if j == n: if i == m : return 1
            if i == m: return 0
            ans = 0
            counts = cnt[(i,target[j])]
            if counts > 0 : 
                ans += counts * dp(i+1,j+1)
            ans += dp(i+1,j)
            return ans % M 
                   
        return dp(0,0)
            
            