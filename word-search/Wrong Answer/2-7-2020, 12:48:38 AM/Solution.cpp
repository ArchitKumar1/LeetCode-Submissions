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
    bool dfs(int i ,int j,int pos){
         cout << i << " " << j << " " << B[i][j] << endl;
        if(pos == W.size()) {
            found = 1;
        }
       
        for(int x = -1;x<=1;x++){
            for(int y = -1;y<=1;y++){
                if(x *x + y*y == 1){
                    int X = i+x;
                    int Y = j+y;
                    if(safe(X,Y) && B[i][j] == W[pos]){
                        vis[X][Y] =1;
                        if(W[pos+1])
                        if(dfs(X,Y,pos+1) == 1){
                            return 1;
                        }else{
                            vis[X][Y] = 0;
                        }
                    }
                }
            }
        }
        return 0;
        
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