// https://leetcode.com/problems/guess-number-higher-or-lower-ii

class Solution {
public:
    const int N = 210;
    
    int getMoneyAmount(int n) {
       
        int dp[N][N];
        memset(dp,-1,sizeof(dp));
        
        function<int(int,int)> solve = [&](int l,int h){
            if(l >= h) return 0;
            if(dp[N][N] != -1) return dp[l][h];
            int ans = INT_MAX ;
            for(int x = l;x<=h;x++){
                ans  = min(ans,{ x + max(solve(l,x-1),solve(x+1,h))});
            }
            return dp[l][h] = ans;
        };
        return solve(1,n);
        
    }
};