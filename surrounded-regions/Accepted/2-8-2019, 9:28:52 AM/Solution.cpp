// https://leetcode.com/problems/surrounded-regions

static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<int> movex = {1,0,-1,0};
    vector<int> movey = {0,1,0,-1};
    void dfs(vector<vector<char>>& board, int i, int j)
    {
        if(board[i][j]!='O')return;
        board[i][j]='Y';
        for(int k=0;k<4;k++)
            if(i+movex[k]>=0 && i+movex[k]<board.size() && j+movey[k]>=0 && j+movey[k]<board[i].size() && board[i+movex[k]][j+movey[k]]=='O')
                dfs(board,i+movex[k],j+movey[k]);
    }
    
    void solve(vector<vector<char>>& board) {
        if(board.size()==0)return;
        for(int i=0;i<board.size();i++)
        {
            dfs(board,i,0);
            dfs(board,i,board[i].size()-1);
        }
        for(int i=0;i<board[0].size();i++)
        {
            dfs(board,0,i);
            dfs(board,board.size()-1,i);
        }
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='Y')board[i][j]='O';
                else if(board[i][j]=='O')board[i][j]='X';
            }
    }
};