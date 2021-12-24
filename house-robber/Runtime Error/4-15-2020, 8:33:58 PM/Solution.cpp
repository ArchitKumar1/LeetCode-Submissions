// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+2,0);
        int n = nums.size();
        dp[1] = nums[0];
        for(int i = 0;i<=n;i++){
            if(i+2<=n){
                dp[i+2]= max(dp[i+2],nums[i+1] + dp[i]);
            }
            if(i+1<=n){
                dp[i+1]= max(dp[i+1],dp[i]);
            }
        }
        return dp[n];
    }
};