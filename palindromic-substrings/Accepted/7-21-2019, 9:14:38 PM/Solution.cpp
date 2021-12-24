// https://leetcode.com/problems/palindromic-substrings

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            dp[i][i] = 1;
        }
        for(int i=0;i<n -1;i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = 1;
            }
        }
        for(int k = 2;k<n;k++){
            for(int i = 0;i + k < n;i++){
                if(s[i] == s[i+k]){
                    if(dp[i+1][i+k-1] == 1){
                        dp[i][i+k] =1 ;
                    }
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j] == 1){
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};