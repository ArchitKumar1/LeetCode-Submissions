// https://leetcode.com/problems/minimum-cost-for-tickets

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        map<int,int> m1;
        for(int c : days){
            m1[c] = 1;
        }
        int dp[366];
        for(int i=0;i<366;i++) dp[i] = 1e9;
        dp[0] =0;
        for(int i=1;i<366;i++){
            if(!m1[i]){
                dp[i] = dp[i-1];
            }else{
                dp[i] = min(dp[max(0,i-1)] + costs[0],dp[i]);
                dp[i] = min(dp[max(0,i-7)] + costs[1],dp[i]);
                dp[i] = min(dp[max(0,i-30)] + costs[2],dp[i]);
            }
        }
        for(int i=0;i<365;i++){
            cout << dp[i] << " ";
        }
        return *max_element(dp,dp+366);
    }
};