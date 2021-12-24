// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[nums.size()+1];
        memset(dp,sizeof(dp),0);
        dp[1] = nums[0];
        if(nums.size() == 1)
            return nums[0];
        for(int i=1;i<nums.size();i++){
            dp[i+1] = max(dp[i-1]+nums[i-1],dp[i]);
        }
        return dp[nums.size()];
    }
};