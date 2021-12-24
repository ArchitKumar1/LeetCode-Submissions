// https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary

class Solution:
    def numWays(self, words: List[str], target: str) -> int:
        cnt = defaultdict(int)
        for w in words:
            for i,c in enumerate(w):
                cnt[(i,c)]+=1
        n = len(target)
        m = max([len(w) for w in words])
        @cache    
        def dp(i,j):
            if j == n:
                return 1 if i == m else 0
            if i == m:
                return 0
            ans = 0
            if cnt[(i,target[j])] > 0 : 
                ans += cnt[(i,target[j])] * dp(i+1,j+1)
            ans += dp(i+1,j)
            return ans
                   
        return dp(0,0)
            
            