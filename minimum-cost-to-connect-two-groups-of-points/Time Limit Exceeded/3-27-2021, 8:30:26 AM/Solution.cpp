// https://leetcode.com/problems/minimum-cost-to-connect-two-groups-of-points

class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int n = cost.size();
        int m = cost[0].size();
        
        int N = 1 << n, M = 1 << m;
        
        vector<vector<int>> dp(N,vector<int>(M,1e9));
        dp[0][0] = 0;
        for(int m1 = 0;m1 < N;m1++){
            for(int m2 = 0;m2 < M;m2++){
                for(int i = 0;i < n;i++){
                    for(int j = 0;j < m;j++){
                        int nm1 = m1 |(1 << i);
                        int nm2 = m2 |(1 << j);
                        dp[nm1][nm2] = min(dp[nm1][nm2],dp[m1][m2] + cost[i][j]);
                    }
                }
            }
        }
        return dp[N-1][M-1];
        
    }
};