// https://leetcode.com/problems/cherry-pickup-ii

class Solution {
    static const int N = 80;
public:
    int n,m;
    
    int dp[N][N][N][N];
    int solve(int x1,int y1,int x2,int y2,vector<vector<int>>& G){
        int ans = -1e9;
        if(x1 < 0 || x2 < 0 || x1 >n-1 || x2 > n-1 ||y1 < 0 || y2 < 0 || y1 >m-1 || y2 > m-1  )return   -1e9;
        
        if(dp[x1][y1][x2][y2]!=-1) return dp[x1][y1][x2][y2];
        // cout << x1 << " " << x2 << " " << y1 << " " << y2 << endl;
        else if(x1 == n-1 && x2 == n-1){
            if(y1 == y2) {
                // cout << x1 << " " << y1 << endl;
                ans =  G[x1][y1];
            }
            else {
                // cout << x1 << " " << y1 <<  " " <<x2 << " " << y2 << endl;
                ans =  G[x1][y1] + G[x2][y2];
            }
        }
        else if(x1 == x2 && y1 == y2) {
            ans = G[x1][y1];
        }else{
            for(int i = -1;i<=1;i++){
                for(int j = -1;j<=1;j++){
                    ans = max(ans,G[x1][y1] + G[x2][y2] + solve(x1+1,y1+i,x2+1,y2+j,G));
                }
            }
        }
        return ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
         n = grid.size();
         m = grid[0].size();
        
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,0,0,m-1,grid);
        return (ans <= -1e9 ? 0 : ans);
    }
};