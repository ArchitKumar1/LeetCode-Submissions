// https://leetcode.com/problems/palindrome-partitioning-iii

class Solution {
public:
    int palindromePartition(string s, int k) {
        int n =s.size();
        int dp[n+1][n+1];
        for(int l =0 ;l<n;l++){
            for(int i =0;i+l<n;i++){
                int j = i+l;
                if(i == j){
                    dp[i][j] = 0;
                }else{
                    if(s[i] == s[j]){
                        dp[i][j] = dp[i+1][j-1];
                    }else{
                        dp[i][j] = 1 + dp[i+1][j-1];
                    }
                }
            }
        }
        
        int dp2[n+1][k+1] = {0};
        for(int i = 0;i<n;i++){
            dp2[i][1] = dp[0][i];
        }
        for(int cnt = 2;cnt<=k;cnt++){
            for(int i =0;i<n;i++){
                dp2[i][cnt] = i;
                for(int j = 0;j<=i;j++){
                    dp2[i][cnt] = min(dp2[i][cnt],dp2[j][cnt-1] + dp[j+1][i]);
                }
            }
        }
        return dp2[n-1][k];
        
    }
};