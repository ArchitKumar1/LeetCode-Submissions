// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

class Solution {
public:
    int N,K;
    vector<int> P;
    
    
    int solve(int i,int k){
        if(i<0 || K<0) return 0;
        int ans = INT_MIN;
        int mi = INT_MAX;
        for(int j = i-1;j>=0;j--){
            mi = min(mi,P[j]);
            if(mi < P[i]){
                ans = max(ans, P[i] - mi + solve(j-1,k-1));
            }
            ans = max(ans,solve(j,k));
        }
        return ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        K = k, N= prices.size();
        P = prices;
        return solve(N-1,K);
    }
};