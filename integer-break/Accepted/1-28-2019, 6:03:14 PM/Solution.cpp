// https://leetcode.com/problems/integer-break

class Solution {
public:
    int integerBreak(int n) {
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[1]=0;
        dp[2]=1;
        for(int i=3;i<=n;i++){
            int temp=-1;
            for(int j=1;j<i;j++)
                temp=max(j*max(i-j,dp[i-j]),temp);
            dp[i]=temp;
        }
        return dp[n];
            
    }
};