// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans;
        int n = prices.size();
        for(int i = 0;i<n;i++){
            int total = prices[i];
            for(int j = i+1;j<n;j++){
                if(prices[j]<=prices[i]){
                    total = max(0,total-prices[j]);
                    j = n;
                }
            }
            ans.push_back(total);
        }return ans;
    }
};