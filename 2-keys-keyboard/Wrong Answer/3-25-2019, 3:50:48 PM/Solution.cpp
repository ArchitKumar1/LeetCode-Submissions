// https://leetcode.com/problems/2-keys-keyboard

class Solution {
public:
    int minSteps(int n) {
        if(n == 1){
            return 0;
        }
        if(n==2){
            return 2;
        }
        int dp[n+1];
        memset(dp,sizeof(dp),0);
        
        dp[1] = 0;
        dp[2] = 2;
        for(int i=3;i<=n;i++){
            if(i%2 == 0){
                dp[i] = 2 + dp[i/2];
            }
            if(i%2 == 1){
                dp[i] = dp[1] + 1 + n - 1;
            }
        }
        return dp[n];
    }
};