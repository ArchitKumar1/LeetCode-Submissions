// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,0);
        int n = nums.size();
        for(int i = 0;i<=n;i++){
            if(i+2<=n){
                dp[i+2]= max(dp[i+1],nums[i] + dp[i]);
            }
            if(i+1<=n){
                dp[i+1]= max(dp[i+1],dp[i]);
            }
        }
        return dp[n];
    }
};