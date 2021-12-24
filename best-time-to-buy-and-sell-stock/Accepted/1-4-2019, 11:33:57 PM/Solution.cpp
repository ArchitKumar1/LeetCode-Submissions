// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxdiff=0;
        for(int i=0;i<prices.size();i++){
            for(int j=i+1;j<prices.size();j++){
                maxdiff=max(maxdiff,prices[j]-prices[i]);
            }
        }
        return maxdiff;
    }
};