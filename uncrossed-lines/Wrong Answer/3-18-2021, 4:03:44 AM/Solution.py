// https://leetcode.com/problems/uncrossed-lines

class Solution:
    def maxUncrossedLines(self, A: List[int], B: List[int]) -> int:
        # A = [0] + A
        # B = [0] + B
        
        N ,M = len(A)+1,len(B)+1
        
        dp  = [[0]*M] * N
        print(dp)
        for i in range(1,N):
            for j in range(1,M):
                if i==0 or j==0:
                    dp[i][j]=0
                elif A[i-1] == B[j-1]:
                    dp[i][j] = 1 + dp[i-1][j-1]
                else:
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1])
                print(dp)
        print(dp)
        return dp[N-1][M-1]