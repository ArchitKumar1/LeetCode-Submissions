// https://leetcode.com/problems/minimum-cost-to-connect-two-groups-of-points

class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int n = cost.size();
        int m = cost[0].size();
        
        int N = 1 << n, M = 1 << m;
        
        vector<vector<int>> dp(n+1,vector<int>(M,1e9));
        
        vector<int> mini(n,INT_MAX);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                mini[i] = min(mini[i],cost[i][j]);
            }
        }
        dp[0][0] = 0;
        for(int s = 1;s <= n;s++){
            for(int j = 0;j < m;j++){
                for(int m2 = 0;m2 < M;m2++){
                
                    int nm2 = m2 ^ (1 << j);
                    dp[s][m2] = min({dp[s][m2], dp[s-1][nm2] + cost[s-1][j],dp[s][nm2] + cost[s-1][j]});
                } 
            }
        }
        return dp[n][M-1];
        
    }
};