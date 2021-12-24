// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int s= prices[0];
        int ans = 0;
        for(int c: prices){
            ans = max(ans,c - s);
            s = min(s,c);
        }
        return ans;
    }
};