// https://leetcode.com/problems/count-different-palindromic-subsequences

class Solution:
    def countPalindromicSubsequences(self, s: str) -> int:
        
        @functools.lru_cache(None)
        def solve(i,j):
            if(i > j):
                return 0
            if(i == j):
                return 1
            return solve(i+1,j) + solve(i,j-1) - solve(i+1,j-1) + (1 if s[i] == s[j] else 0)
        
        return solve(0,len(s)-1)
    
            