// https://leetcode.com/problems/toeplitz-matrix

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& M) {
        int n = M.size();
        int m = M[0].size();
        //if( (m == 1) ^ (n == 1)) return 1;
        bool ok = 1;
        for(int i=0;i<n;i++){
            int x = i;
            int y = 0;
            int curr = M[x][y];
            while(++x < n && ++y < m){
                ok&= (curr == M[x][y]);
            }
        }
        for(int j=0;j<m;j++){
            int x = 0;
            int y = j;
            int curr = M[x][y];
            while(++x < n && ++y < m){
                ok&= (curr == M[x][y]);
            }
        }
        return ok;
    }
};