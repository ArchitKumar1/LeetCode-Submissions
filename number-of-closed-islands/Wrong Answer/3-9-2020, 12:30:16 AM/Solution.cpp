// https://leetcode.com/problems/number-of-closed-islands

class Solution {
public:
    int N,M;
    int cnt = 0;
    bool s = 1;
    vector<vector<int>>vis,G;
    bool safe(int i,int j){
        return i>=0 && j>=0 && i<N && j<M;
    }
    bool border(int i,int j){
        return (i == 0 || i == N-1) && (j == 0 || j == M-1);
    }
    void dfs(int i,int j){
        if(!safe(i,j)) return;
        if(G[i][j] == 1) return;
        if(vis[i][j] == 1) return;
        if(border(i,j)){
            s = 0;
        }
        vis[i][j] = 1;
        dfs(i+1,j);
        dfs(i-1,j);
        dfs(i,j-1);
        dfs(i,j+1);
        
    }
    int closedIsland(vector<vector<int>>& grid) {
        N = grid.size();
        M = grid[0].size();
        G = grid;
        vis = vector<vector<int>>(N,vector<int>(M,0));
        int is = 0;
        for(int i = 0;i<N;i++){
            for(int j = 0;j<M;j++){
                cnt = 0;
                s = 1;
                if(!vis[i][j] && G[i][j] == 0){
                    dfs(i,j);
                    if(s){
                        is +=1;
                    }
                }
            }
        }
        return is;
    }
};