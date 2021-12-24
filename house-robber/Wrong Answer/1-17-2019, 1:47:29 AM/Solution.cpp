// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        int dp[n];
        dp[0]=nums[0];
        dp[1]=nums[1];
        for(int i=2;i<nums.size();i++)
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        return dp[n-1];
    }
};