// https://leetcode.com/problems/surrounded-regions

class Solution {
public:
    void dfs(vector<vector<char>> & board, int i,int j){
        if(board[i][j] == 'O' and i>0 && j>0 && i<n-1 && j<m-1){
            board[i][j]='X';
            dfs(board,i-1,j);
            dfs(board,i-1,j)
            
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;i++){
                if(board[i][j]=='O'){
                    dfs(board,i,j);
                }
            }
        }
    }
};