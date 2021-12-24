// https://leetcode.com/problems/score-after-flipping-matrix

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int N =  A.size();
        int M = A[0].size();
        int res = (1 << M-1)*N;
        
        for(int j=1;j<M;j++){
            int cur = 0;
            
            for(int i=0;i<N;i++){
                cur += A[i][j] == A[i][0];    
            }
            res+= max(cur,N-cur)* (1 << (M - 1- j));
        }
        return res;
    }
};