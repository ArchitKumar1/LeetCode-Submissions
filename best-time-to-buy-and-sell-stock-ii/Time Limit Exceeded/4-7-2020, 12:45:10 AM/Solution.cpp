// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n+1,0);
        dp[0] = 0;
        for(int i = 1;i<=n;i++){
            for(int j = i+1;j<=n;j++){
                dp[j] = dp[j-1];
                for(int k = i;k<j;k++){
                    if(prices[k-1] < prices[j-1]){
                
                        dp[j] = max(dp[j] ,dp[i] + prices[j-1] - prices[k-1]);
                    }
                }
            }
        }
        return dp[n];
    }
};