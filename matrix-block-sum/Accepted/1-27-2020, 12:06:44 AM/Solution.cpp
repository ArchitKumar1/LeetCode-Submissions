// https://leetcode.com/problems/matrix-block-sum

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                dp[i][j] = mat[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }
        vector<vector<int>> dp1(n,vector<int>(m,0));
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                int x2= min(i+K,n);
                int y2 = min(j+K,m); 
                int x1 = max(1,i-K);
                int y1 =max(1,j-K);
                dp1[i-1][j-1] = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];
            }
        }
        return dp1;
    }
};