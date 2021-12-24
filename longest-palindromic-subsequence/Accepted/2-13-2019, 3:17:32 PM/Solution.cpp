// https://leetcode.com/problems/longest-palindromic-subsequence

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();

        int dp[n][n];
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;
        for(int x = 2; x <= n; x++){
            for(int i = 0; i < n - x + 1;i++){
                int j = i + x - 1;
                if( s[i] == s[j] && x==2)
                    dp[i][j] = 2;
                else if (s[i] == s[j])
                    dp[i][j]=dp[i+1][j-1] + 2;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
        }
        return dp[0][n-1];
    }
};