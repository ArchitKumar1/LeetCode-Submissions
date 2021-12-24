// https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other

class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        int H = 40;
        int M = 1 << n;
        
        int dp[H+1][1 << M];
        memset(dp,0,sizeof(dp));
        
        map<int,set<int>> m1;
        for(int i = 0;i<n;i++){
            auto p = hats[i];
            for(auto h : p){
                m1[h].insert(i);
            }
        }
        
        dp[0][0] = 1;
        for(int i = 1;i<=H;i++){
            for(int j = 0; j < M;j++){
                dp[i][j] =  dp[i-1][j];
                for(int p : m1[i]){
                    if(j&(1<<p) == 0){
                        dp[i][j|(1 << p)] += dp[i-1][j];
                    }
                }
            }
        }
        for(int j = 0;j<M;j++){
            cout << dp[H][j] << " ";
        }
        return dp[H][M-1];
    }
};