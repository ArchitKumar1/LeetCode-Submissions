// https://leetcode.com/problems/decode-ways

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        
        for(int i=1;i<n;i++){
            dp[i] = dp[i-1] + 1;
            if(i-2 >= 0){
                int y = (s[i-1] - 0) * 10 + (s[i] - 0);
                if(y<=26){
                    dp[i] += dp[i-2] + 1;
                }
            }
        }
        return dp[n-1];
    }
};