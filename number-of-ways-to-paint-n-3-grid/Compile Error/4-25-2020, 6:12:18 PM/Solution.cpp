// https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid

class Solution {
    int dp[4][4][4][5100];
public:
    
    int solve(int x,int y,int z,int n){
        
        if (dp[x][y][z][n] != -1)return dp[x][y][z][n];
        int ans =0 ;
        if(n == 0) return 1;
        for(int i = 1;i<=3;i++){
            for(int j = 1;j<=3;j++){
                for(int k = 1;k<=3;k++){
                    if(i == x || j == y || k == z){
                        continue;
                    }
                    if(i == j || j == k) continue;
                    (ans += solve(i,j,k,n-1))%=mod;
                }
            }
        }
        return dp[x][y][z][n] = ans;
    }
    
    int numOfWays(int n) {
        
        int ans = 0;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,n);
        
    }
};