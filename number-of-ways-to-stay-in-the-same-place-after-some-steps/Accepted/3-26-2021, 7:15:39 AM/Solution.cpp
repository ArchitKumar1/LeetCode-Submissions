// https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps

const int N = 510;
const int M = 1e9+7;

class Solution {
public:

    int numWays(int steps, int arrLen) {
        int n = min(N,arrLen);
        vector<int> dp(n);
        dp[0] = 1;
        
        while(steps--){
            vector<int> ndp(n);
            
            for(int i = 0;i < n;i++){
                if(i > 0) ndp[i] += dp[i-1];
                ndp[i] %= M;
                if(i < n - 1) ndp[i] += dp[i+1];
                ndp[i] %= M;
                ndp[i] += dp[i];
                ndp[i] %= M;
            } 
            swap(ndp,dp);
        }
        return dp[0];
    }
};