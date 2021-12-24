// https://leetcode.com/problems/interleaving-string

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        int o = s3.length();
        
        int dp[n+1][m+1] = {0};
        if(o!= n+m) return 0;
        for(int i = 0;i<=n;i++){
            for(int j = 0;j<=m;j++){
                if(i == 0 && j == 0) dp[i][j] = 1;
                else if(i == 0){
                    if(dp[i][j-1] && s2[j-1] == s3[i+j-1]){
                        dp[i][j] = 1;
                    }
                }else if(j == 0){
                    if(dp[i-1][j] && s1[i-1] == s3[i+j-1]){
                        dp[i][j] = 1;
                    }
                }else{
                    if(dp[i][j-1] && s2[j-1] == s3[i+j-1]){
                        dp[i][j] = 1;
                    }
                    if(dp[i-1][j] && s1[i-1] == s3[i+j-1]){
                        dp[i][j] = 1;
                    }
                }
            }
        }
        return dp[n][m];
    }
};