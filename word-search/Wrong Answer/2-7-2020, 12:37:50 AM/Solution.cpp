// https://leetcode.com/problems/word-search

class Solution {
public:
    bool found = 0;
    int N,M;
    string W ;
    vector<vector<char>> B;
    vector<vector<bool>>vis;
    bool safe(int i,int j){
        return( i>=0 && j>=0 && i<N && j<M);
    }
    void dfs(int i ,int j,int pos){
        
        if(pos == W.size()) {
            found = 1;
            return ;
        }
        if(!safe(i,j)) return;
        if(vis[i][j] == 1 || (B[i][j]!=W[pos]))return ;
        cout << i << " " << j << " " << B[i][j] << endl;
        vis[i][j] = 1;
        dfs(i+1,j,pos+1);
        dfs(i,j+1,pos+1);
        dfs(i-1,j,pos+1);
        dfs(i,j-1,pos+1);
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        N = board.size();
        M = board[0].size();
        W = word;
        B = board;
        for(int i = 0;i<N;i++){
            for(int j = 0;j<M;j++){
                vis = vector<vector<bool>>(N,vector<bool>(M,0));
                dfs(i,j,0);
            }
        }
        return found;
    }
};