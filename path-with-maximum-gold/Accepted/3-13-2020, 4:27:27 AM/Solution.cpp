// https://leetcode.com/problems/path-with-maximum-gold

class Solution {
public:
    int N,M;
    int ans = 0;
    vector<vector<int>> vis,G;
    
    const int dx[4] = {0,1,0,-1};
    const int dy[4] = {1,0,-1,0};
    
    bool in(int i,int j){
        return i>=0 && j>=0 && i<N && j<M;
    }
    
    int solve(int i,int j){
        if(!in(i,j) || G[i][j] == 0 || vis[i][j] == 1){
            return 0;
        }
        vis[i][j] = 1;
        int tans = G[i][j];
        int temp = 0;
        for(int k = 0;k<4;k++){
            temp = max(temp,solve(i+dx[k],j+dy[k]));
        }
        vis[i][j] = 0;
        
        return tans + temp;  
    }
    
    
    
    int getMaximumGold(vector<vector<int>>& grid) {
        N = grid.size();
        M = grid[0].size();
        vis = vector<vector<int>>(N,vector<int>(M,0));
        G = grid;
        
        int fans = 0;
        for(int i = 0;i<N;i++){
            for(int j = 0;j<M;j++){
                solve(i,j);
                fans = max(fans,solve(i,j));
            }
        }
        return fans;
        
    }
};