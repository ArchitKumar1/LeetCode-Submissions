// https://leetcode.com/problems/sudoku-solver

class Solution {
public:
    int n = 9;
    bool issafe(int r,int c,char val,vector<vector<char>>& board){
        int r1 = r / 3;
        int c1 = c / 3;
        for (int i = 0; i < n;i++) if(board[i][c] ==  val) return 0;
        for (int j = 0; j < n;j++) if(board[r][j] ==  val) return 0;
        for (int i = 3 * r1; i < 3 * (r1 + 1); i++){
            for (int j = 3 * c1; j < 3 * (c1 + 1); j++){
                if(board[i][j] == val)
                    return 0;
            }
        }
        return 1;
    }
    bool next(int &i,int &j,vector<vector<char>>& board){
        for (i = 0; i < n;i++) for (j = 0; j < n;j++) if(board[i][j] == '.') return 1;
            return 0;
    }
    bool solve(vector<vector<char>>& board){
        int r, c;
        if(!next(r, c,board)) return 1;
        for (int i = 1; i <= n;i++){
            char val = '0' + i;
            if(issafe(r,c,val,board)){
                board[r][c] = val;
                if(solve(board) == 1) return 1;
                else board[r][c] = '.';
            }
        }
        return 0;
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool d = solve(board);
    }
};