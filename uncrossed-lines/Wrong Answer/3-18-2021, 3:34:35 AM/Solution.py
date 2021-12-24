// https://leetcode.com/problems/uncrossed-lines

class Solution:
    def maxUncrossedLines(self, A: List[int], B: List[int]) -> int:
        A = [0] + A
        B = [0] + B
        
        N ,M = len(A),len(B)
        
        dp  = [[0]*M] * N
        print(dp)
        for i in range(1,N):
            for j in range(1,M):
                if A[i] == B[j]:
                    dp[i][j] = max(dp[i][j],1 + dp[i-1][j-1])
                    
        
        return max([max(x) for x in dp])