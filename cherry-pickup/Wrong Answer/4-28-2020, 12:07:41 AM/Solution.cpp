// https://leetcode.com/problems/cherry-pickup

class Solution {
public:
    int n, m;
    vector<vector<int>> G;
    
    bool safe(int x,int y){
        return x>=0 && y>=0 && x<n && y<m;
    }
    
    int solve(int x1,int y1,int x2,int y2){
        if(x1 == n-1 && y1 == m-1 && x2 == n-1 && y2 == m-1){
            return G[n-1][m-1];
        }
        if(!safe(x1,y1) || !safe(x2,y2)){
            return -1e9;
        }
        if(G[x1][y1] == -1 || G[x2][y2] == -1){
            return -1e9;
        }
        int ans = 0;
        if(x1 == x2 && y1 == y2){
            ans = G[x1][y1];
        }else{
            ans = G[x1][y1] + G[x2][y2];
        }
        int temp = 0;
        temp = max(temp,solve(x1+1,y1,x2+1,y2));
        temp = max(temp,solve(x1+1,y1,x2,y2+1));
        temp = max(temp,solve(x1,y1+1,x2+1,y2));
        temp = max(temp,solve(x1,y1+1,x2,y2+1));
        
        return ans + temp;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        G = grid;
        n = grid.size();
        m = grid[0].size();
        
        return solve(0,0,0,0);
        
        
    }
};