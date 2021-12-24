// https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp1[n+1];
        dp1[0] = 0;
        for(int i=1;i<=n;i++){
            dp1[i] = cost[i-1] + min(i-1>=0 ? dp1[i-1] : (int)1e9,i-2 >=0 ? dp1[i-2] : (int) 1e9);
        }
        return min(dp1[n],dp1[n-1]);
    }
};