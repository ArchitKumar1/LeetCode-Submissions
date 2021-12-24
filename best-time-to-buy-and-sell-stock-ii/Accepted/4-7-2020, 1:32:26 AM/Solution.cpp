// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n+1,0);
        dp[0] = 0;
//         for(int i = 1;i<=n;i++){
//             for(int j = i+1;j<=n;j++){
//                 dp[j] = dp[j-1];
//                 for(int k = i;k<j;k++){
//                     if(prices[k-1] < prices[j-1]){
                
//                         dp[j] = max(dp[j] ,dp[i] + prices[j-1] - prices[k-1]);
//                     }
//                 }
//             }
//         }
//         for(int i = 1;i<=n;i++){
//             int mini = 1e9;
//             for(int j = i+1;j<=n;j++){
//                 dp[j] = max(dp[j],dp[j-1]);
//                 mini =  min(mini,prices[j-2]);
//                 if(mini< prices[j-1]){
//                     dp[j] = max(dp[j] ,dp[i] + prices[j-1] - mini);
//                 }
                
//             }
//         }
        // return dp[n];
        int s = 0;
        for(int i = 0;i+1<n;i++){
            s += max(prices[i+1] - prices[i],0);
        }
        return s;
    }
};