// https://leetcode.com/problems/count-sorted-vowel-strings

class Solution {
public:
    int countVowelStrings(int n) {
        
        int N = 50;
        
        int dp[55][6];
        
        memset(dp,0,sizeof(dp));
        
        dp[0][0] = 1;
        
        for(int i =1 ;i<=n;i++){
            for(int j = 0;j<5;j++){
                for(int k = 0;k<=j;k++){
                    dp[i][j] += dp[i-1][k];
                }
            }
        }
        int ans = 0;
        for(int j = 0;j<5;j++){
            ans += dp[n][j];
        }
        return ans;
    }
};