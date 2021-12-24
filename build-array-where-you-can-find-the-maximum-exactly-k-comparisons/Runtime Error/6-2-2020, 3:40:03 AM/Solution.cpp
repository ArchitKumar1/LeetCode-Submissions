// https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons

class Solution {
public:
    int dp[51][101][50];
    int solve(int i,int j,int k){
        if(i < 0 || j < 0 || k < 0) return 0;
        if(i == 1 && k == 1 && j >= 1) return 1;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        int ans = 0;
        
        ans += j*solve(i-1,j,k);
        for(int x = 0;x<j;x++){
            ans += solve(i-1,x,k-1);
        }
        return dp[i][j][k] = ans;
        
    }
    int numOfArrays(int n, int m, int k) {
        int ans = 0;
        memset(dp,-1,sizeof(dp));
        for(int j = 1;j<=m;j++){
            ans += solve(n,j,k);
        }
        return ans;
    }
};