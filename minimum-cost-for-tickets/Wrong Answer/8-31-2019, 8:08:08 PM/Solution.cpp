// https://leetcode.com/problems/minimum-cost-for-tickets

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> sabdin{1,7,30};
        map<int,int> m1;
        for(int c : days){
            m1[c] = 1;
        }
        int dp[366];
        dp[0] = 0;
        for(int i=1;i<366;i++){
            dp[i] = 1e9;
            if(!m1[i]){
                dp[i] = dp[i-1];
            }else{
                for(int j = 0;j<3;j++){
                    if(i - sabdin[j] >= 0){
                        dp[i] = min(dp[i],dp[i-sabdin[j]] + costs[j]);
                    }
                }
            }

        }
        
        return *max_element(dp,dp+366);
    }
};