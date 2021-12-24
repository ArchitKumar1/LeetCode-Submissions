// https://leetcode.com/problems/maximal-square

class Solution {
public:
    int maximalSquare(vector<vector<char>>& ma) {
        
        int n = ma.size();
        int m = ma[0].size();
        if(n == 0 || m == 0) return 0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        int ans = 0;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(ma[i-1][j-1] == '1'){
                    dp[i][j] = 1 + min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
                    ans = max(ans,dp[i][j]);
                }
            }
        }
        return ans*ans;
    }
};