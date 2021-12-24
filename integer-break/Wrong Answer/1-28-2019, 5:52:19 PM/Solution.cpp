// https://leetcode.com/problems/integer-break

class Solution {
public:
    int integerBreak(int n) {
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[1]=0;
        dp[2]=1;
        for(int i=3;i<=n;i++) {
            for(int j=1;j<=n;j++){
                if(i%j==0){
                    dp[i]=max(dp[i],dp[i/j]);
                }
            }
        }
        return dp[n];
            
    }
};