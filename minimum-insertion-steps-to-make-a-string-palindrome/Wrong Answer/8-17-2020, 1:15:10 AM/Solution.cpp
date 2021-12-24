// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome

class Solution {
public:
    int minInsertions(string s) {
        int n;
        n = s.size();
        int dp[n][n];
        
        for(int l = 0;l<n;l++){
            for(int i =0;i+l<n;i++){
                int j = i+l;
                dp[i][j] = INT_MAX;
                if(i == j) dp[i][j] = 0;
                else{
                    if(s[i] == s[j]){
                        dp[i][j] = dp[i+1][j-1];
                    }else{
                        dp[i][j] =1 +  min(dp[i+1][j],dp[i][j-1]);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};