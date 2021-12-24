// https://leetcode.com/problems/max-dot-product-of-two-subsequences

class Solution {
public:
    int maxDotProduct(vector<int>& v1, vector<int>& v2) {
        
        int n = v1.size();
        int m = v2.size();
        vector<vector<long long >>dp(n+1,vector<long long>(m+1,0));
        long long ans = 0;
        

        for(int i =1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                dp[i][j] = max(dp[i][j],v1[i-1] * v2[j-1] + dp[i-1][j-1]);
                dp[i][j] = max(dp[i][j],dp[i-1][j]);
                dp[i][j] = max(dp[i][j],dp[i][j-1]);
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};