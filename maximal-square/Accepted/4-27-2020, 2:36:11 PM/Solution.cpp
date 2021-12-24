// https://leetcode.com/problems/maximal-square

class Solution {
public:
    int maximalSquare(vector<vector<char>>& ma) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        if(ma.size() == 0)return 0;
        int n = ma.size();
        int m = ma[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        int ans = 0;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(ma[i-1][j-1] == '1'){
                    dp[i][j] = 1 + min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
                    if(dp[i][j] > ans) ans = dp[i][j];
                }
            }
        }
        return ans*ans;
    }
};