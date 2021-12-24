// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

class Solution {
public:
    int N,K;
    vector<int> P;
    vector<vector<int>> dp;
    
    int solve(int i,int k){
        
        if(i<0 || k==0) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int &ans = dp[i][k] = 0;
        
        int mi = INT_MAX;
        for(int j = i-1;j>=0;j--){
            mi = min(mi,P[j]);
            if(mi <= P[i]){
                ans = max(ans, P[i] - mi + solve(j-1,k-1));
            }
            ans = max(ans,solve(j,k));
        }
        return ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        K = k, N= prices.size();
        dp = vector<vector<int>>(N+1,vector<int>(K+1,-1));
        P = prices;
        int ans = solve(N-1,K);
        return ans==INT_MIN?0:ans;
    }
};