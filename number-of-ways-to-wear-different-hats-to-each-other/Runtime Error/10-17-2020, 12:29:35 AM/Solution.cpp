// https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other

class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        int H = 40;
        int M = 1 << n;
        
        int dp[H+1][M];
        memset(dp,0,sizeof(dp));
        
        map<int,set<int>> m1;
        for(int i = 0;i<n;i++){
            auto p = hats[i];
            for(auto h : p){
                m1[h-1].insert(i);
            }
        }
        
        for(int i = 0;i<M;i++){
            dp[0][i] = 1;
        }
        for(int i = 0;i<H;i++){
            for(int j = 0; j < M;j++){
                if(j == 0){
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] = i == 0 ? 0 : dp[i-1][j];
                for(int h : m1[i]){
                    if(j&(1<<h) != 0){
                        dp[i][j] += dp[i-1][j ^ (1 << h)];
                    }
                }
            }
        }
        // for(int i = 0;i<H;i++){
        //     for(int j = 0;j<M;j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[H-1][M-1];
    }
};