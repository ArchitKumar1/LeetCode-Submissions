// https://leetcode.com/problems/valid-sudoku

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if((board[i][j] > '9' || board[i][j] < '1') && board[i][j] != '.')
                    return false;
                int r1 = i/3;
                int c1 = j/3;
                for(int k= 3*r1 ;k< 3*(r1+1);k++){
                    for(int l= 3*c1 ;l< 3*(c1+1);l++){
                        if(k != i && l != j && board[i][j]!='.'){
                            if(board[k][l] == board[i][j])
                                return false;
                        }
                    }
                }
                for(int k=0;k<9;k++){
                    if(k!= i && board[i][j]!='.' ){
                        if(board[k][j] == board[i][j])
                                return 0;
                    }
                }
                for(int l=0;l<9;l++){
                    if(l!= j && board[i][j]!='.' ){
                        if(board[i][l] == board[i][j])
                                return 0;
                    }
                }
            }
        }
        return true;
    }
};