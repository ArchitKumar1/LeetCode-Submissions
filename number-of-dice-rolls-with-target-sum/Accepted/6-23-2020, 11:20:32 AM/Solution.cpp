// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum

class Solution {
private :
    int dp[35][1100];
public:
    int D,F,T;
    int MOD  = 1e9 + 7;
    
    int solve(int curr,int t){
    
        if(t < 0) return 0;
        if(curr == D){
            if(t == 0) return 1;
            else return 0;
        }
        if(dp[curr][t] !=-1) return dp[curr][t];
        int ans = 0;
        for(int i = 1;i<=F;i++){
            (ans += solve(curr + 1,t - i))%= MOD;
        }
        return dp[curr][t] = ans;
    }
    int numRollsToTarget(int d, int f, int target) {
        D = d,F = f,T = target;
        memset(dp,-1,sizeof(dp));
        return solve(0,T);
        
    }
};