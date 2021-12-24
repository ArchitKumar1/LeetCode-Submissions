// https://leetcode.com/problems/coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1,INT_MAX);
        dp[0] = 0;
        for(int i =0 ;i<=amount;i++){
            for(int c : coins){
                if(i + c <=amount){
                    dp[i+c] = min(dp[i+c],1+dp[i]);
                }
            }
        }
        for(int i =0 ;i<=amount;i++){
            cout << dp[i] << " ";
        }
        return dp[amount]==INT_MAX? -1:dp[amount];
    }
};