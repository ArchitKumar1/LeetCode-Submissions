// https://leetcode.com/problems/n-queens-ii

class Solution {
public:
    int grid[100][100];
    int n;  
    
    bool issafe(int r,int c){
        for (int i = r ,j = c ; i >=0 && j>=0;i--,j--){
            if(grid[i][j] == 1)
                return 0;
        }
        for (int i = r ,j = c ; i >=0 && j<n;i--,j++){
            if(grid[i][j] == 1)
                return 0;
        }
        for (int i = 0; i <=r;i++){
            if(grid[i][c] == 1)
                return 0;
        }
        for (int j = 0; j <=c;j++){
            if(grid[r][j] == 1)
                return 0;
        }
        return 1;
    }
    
    int total = 0;
    void nqueen(int row){
        if(row == n)
            total+=1;
        for (int j = 0; j < n;j++){
            if(issafe(row,j)){
                grid[row][j] = 1;
                nqueen(row + 1);
                grid[row][j] = 0;
            }
        }
    }
    int totalNQueens(int n1) {
        n = n1;
        nqueen(0);
        return total;
    }
};