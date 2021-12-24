// https://leetcode.com/problems/minimum-cost-to-connect-two-groups-of-points

class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int n = cost.size();
        int m = cost[0].size();
        
        int N = 1 << n, M = 1 << m;
        
        vector<vector<int>> dp(n+1,vector<int>(M,1e9));
        dp[0][0] = 0;
        for(int s = 0;s < n;s++){
            for(int m2 = 0;m2 < M;m2++){
                for(int j = 0;j < m;j++){
                    int nm2 = m2 |(1 << j);
                    dp[s+1][nm2] = min(dp[s+1][nm2],dp[s][m2] + cost[s][j]);
                } 
            }
        }
        return dp[n][M-1];
        
    }
};