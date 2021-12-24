// https://leetcode.com/problems/toeplitz-matrix

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& M) {
        int n = M.size();
        int m = M[0].size();
        
        bool ok = 1;
        for(int i=0;i<n;i++){
            int x = i;
            int y = 0;
            int curr = M[x][y];
            while(x < n && y < m){
                ok&= (curr == M[x++][y++]);
            }
        }
        for(int j=0;j<n;j++){
            int x = 0;
            int y = j;
            int curr = M[x][y];
            while(x < n && y < m){
                ok&= (curr == M[x++][y++]);
            }
        }
        return ok;
    }
};