// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int MIN = 1 << 30, MAX= 0;
        for(int i=0;i<prices.size();i++){
            MIN = min(prices[i],MIN);
            if(prices[i] < MAX) MAX = 0;
            MAX = max(prices[i],MAX);
            ans = max(ans,MAX-MIN);
        }
        return ans;
    }
};