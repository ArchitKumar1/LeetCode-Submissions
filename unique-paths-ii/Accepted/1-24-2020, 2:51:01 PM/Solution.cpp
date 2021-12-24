// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();

        vector<vector<long>> dp(n,vector<long> (m,0));
        dp[0][0]  = !g[0][0];
        for(int i = 0;i<n;i++){
            for(int j =0;j<m;j++){
                if(i == 0 && j == 0)continue;
                if(g[i][j] == 1) continue;
                dp[i][j] = (i-1>=0 ? dp[i-1][j] : 0) + (j-1>=0 ? dp[i][j-1] : 0); 
            }
        }
 
        return dp[n-1][m-1];
    }
};