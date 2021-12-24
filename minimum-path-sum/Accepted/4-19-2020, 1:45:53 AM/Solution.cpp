// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    int n,m;
    vector<vector<int>>dp;
    int solve(int i,int j,vector<vector<int>>&grid){
        if(i < 0 || j < 0 )return 1e9;
        if(i == 0 && j == 0) return grid[0][0];
        if(dp[i][j]!=- 1)return dp[i][j];
        return dp[i][j] = grid[i][j]+ min(solve(i-1,j,grid),solve(i,j-1,grid));
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp = vector<vector<int>>(n,vector<int>(m,-1));
        return solve(n-1,m-1,grid);
    }
};