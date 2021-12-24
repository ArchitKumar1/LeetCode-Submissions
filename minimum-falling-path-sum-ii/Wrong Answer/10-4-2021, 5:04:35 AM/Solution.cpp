// https://leetcode.com/problems/minimum-falling-path-sum-ii

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& G) {
        
        int n = G.size();
        int m = G[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        
        dp[0] = G[0];
        for(int i = 1;i < n;i++){
            for(int j = 0; j < m;j++){
                if( j > 0) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + G[i][j]);
                if( j < (m - 1)) dp[i][j] = min(dp[i][j], dp[i-1][j+1] + G[i][j]);
            }
            // for(int j = 0; j < m;j++){
            //     cout << dp[i][j] <<  " ";
            // }
            // cout << endl;
            
        }
        
        int ans = INT_MAX;
        for(int j = 0; j < m;j++){
            ans = min(ans,dp[n-1][j]);
        }
        return ans;
    }
};