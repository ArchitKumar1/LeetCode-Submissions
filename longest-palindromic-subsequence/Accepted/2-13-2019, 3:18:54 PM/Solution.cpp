// https://leetcode.com/problems/longest-palindromic-subsequence

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = s.length();
        
        int dp[n][n];
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;
        for(int x = 2; x <= n; x++){
            for(int i = 0; i < n - x + 1;i++){
                if( s[i] == s[i + x - 1] && x==2)
                    dp[i][i + x - 1] = 2;
                else if (s[i] == s[i + x - 1])
                    dp[i][i + x - 1] = dp[i+1][i + x - 1-1] + 2;
                else
                    dp[i][i + x - 1] = max(dp[i][i + x - 1-1], dp[i+1][i + x - 1]);
            }
        }
        return dp[0][n-1];
    }
};