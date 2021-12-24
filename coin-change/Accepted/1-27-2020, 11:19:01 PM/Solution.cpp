// https://leetcode.com/problems/coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = coins.size();
        vector<long long int> dp(amount+1,1e18);
        dp[0] = 0;
        for(int i =0 ;i<=amount;i++){
            for(long long int c : coins){
                if(i + c <=amount){
                    if(dp[i+c] > dp[i] + 1)dp[i+c] = dp[i]+1;
                }
            }
        }
        return dp[amount]>=1e18? -1:dp[amount];
    }
};