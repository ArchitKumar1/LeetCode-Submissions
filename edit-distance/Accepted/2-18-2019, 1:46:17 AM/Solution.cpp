// https://leetcode.com/problems/edit-distance

class Solution {
public:
    int minDistance(string word1, string word2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int n = word1.length();
        int m = word2.length();
    
        int dp[n+1][m+1];
        dp[0][0] = 0;
        for(int i=1;i<n+1;i++) dp[i][0] = 1 + dp[i-1][0];
        for(int i=1;i<m+1;i++) dp[0][i] = 1 + dp[0][i-1];
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else 
                    dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            }
        }
        return dp[n][m];
    }
};