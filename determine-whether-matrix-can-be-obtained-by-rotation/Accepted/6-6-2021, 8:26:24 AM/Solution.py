// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation

class Solution:
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        def solve(matrix):
            N = len(matrix[0])
            for i in range(N // 2):
                for j in range(i, N - i - 1):
                    xx = matrix[i][j]
                    matrix[i][j] = matrix[N - 1 - j][i]
                    matrix[N - 1 - j][i] = matrix[N - 1 - i][N - 1 - j]
                    matrix[N - 1 - i][N - 1 - j] = matrix[j][N - 1 - i]
                    matrix[j][N - 1 - i] = xx
        for i in range(4):
            solve(mat)
            if( mat == target):
                return True
        return False