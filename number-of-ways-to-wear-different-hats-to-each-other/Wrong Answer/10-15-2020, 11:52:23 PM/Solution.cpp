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
            for(auto x : hats[i]){
                m1[i].insert(x);
            }
        }
        
        for(int i = 0;i<M;i++){
            dp[0][i] = 1;
        }
        for(int i = 1;i<=H;i++){
            for(int j = 0; j < M;j++){
                dp[i][j] =  dp[i-1][j];
                for(int k = 0;k < n;k++){
                    if(j&(1<<k) == 0 && m1[k].find(i)!=m1[k].end()){
                        dp[i][j|(1 << k)] += dp[i][j];
                    }
                }
            }
        }
        for(int j = 0;j<M;j++){
            cout << dp[H][j] << endl;
        }
        return dp[H][M-1];
    }
};