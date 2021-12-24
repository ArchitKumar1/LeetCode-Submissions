// https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int length=cost.size();
        int dp[length+1];
        dp[0]=0;
        dp[1]=cost[0];
        dp[2]=min(cost[0],cost[1]);
        for(int i=3;i<=length;i++){
            dp[i]=min(cost[i-1]+dp[i-1],cost[i-2]+dp[i-2]);
        }
        return dp[length];
    }
};