// https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int length=cost.size();
        if(length==0) return 0;
        if(length==1) return cost[0];
        int dp[length+1];
        dp[0]=0;
        dp[1]=cost[0];
        for(int i=2;i<=length;i++)
            dp[i]=min(dp[i-1]+cost[i-2],dp[i-2]+cost[i-2]);
        return dp[length];
    }
};