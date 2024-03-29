// https://leetcode.com/problems/knight-dialer

class Solution {
public:
    int mod = 1e9+7;
    int knightDialer(int N) {
        int dp[N+1][11]={0};
        for(int i =0;i<10;i++){
            dp[1][i] = 1;
        }
        for(int i =2;i<=N;i++){
            dp[i][0] = (dp[i-1][4] + dp[i-1][6])%mod;
            dp[i][1] = (dp[i-1][6] + dp[i-1][8])%mod;
            dp[i][2] = (dp[i-1][7] + dp[i-1][9])%mod;
            dp[i][3] = (dp[i-1][4] + dp[i-1][8])%mod;
            dp[i][4] = ((dp[i-1][3] + dp[i-1][9])%mod + dp[i-1][0])%mod;
            dp[i][5] = 0;
            dp[i][6] = ((dp[i-1][1] + dp[i-1][7])%mod + dp[i-1][0])%mod;
            dp[i][7] = (dp[i-1][2] + dp[i-1][6])%mod;
            dp[i][8] = (dp[i-1][1] + dp[i-1][3])%mod;
            dp[i][9] = (dp[i-1][2] + dp[i-1][4])%mod;
        }
        int ans = 0;
        for(int i =0;i<10;i++){
            ans  = (ans+ dp[N][i])%mod;
        }
        return ans;
    }
};