// https://leetcode.com/problems/cherry-pickup

class Solution {
    
    private:
    int dp[51][51][51][51];
public:
    int n, m;
    vector<vector<int>> G;
    
    
    
    bool safe(int x,int y){
        return x>=0 && y>=0 && x<n && y<m;
    }
    int vis = 0;
    int solve(int x1,int y1,int x2,int y2){
        if(!safe(x1,y1) || !safe(x2,y2)){
            return -1e9;
        }
        if(G[x1][y1] == -1 || G[x2][y2] == -1){
            return -1e9;
        }
        if(x1 == n-1 && y1 == m-1 && x2 == n-1 && y2 == m-1){
            if(G[n-1][m-1] == -1) return -1e9;
            else return G[n-1][m-1];
        }
        
        if(dp[x1][y1][x2][y2]!=0){
            return dp[x1][y1][x2][y2];
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
        
        // cout << x1 << " " << x2 << " " << y1 << " " << y2 << " " << ans + temp << endl;
        
        return dp[x1][y1][x2][y2] = ans + temp;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        G = grid;
        n = grid.size();
        m = grid[0].size();
        
        memset(dp,0,sizeof(dp));
        int ans = solve(0,0,0,0) ;
        return vis ? ans: 0;
        
        
    }
};