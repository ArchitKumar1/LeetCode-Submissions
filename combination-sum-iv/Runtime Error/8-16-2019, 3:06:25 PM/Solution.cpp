// https://leetcode.com/problems/combination-sum-iv

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=  nums.size();
        
        int dp[target + 2] = {0};
        dp[0] = 1;
        for (int j = 1; j <= target;j++){
            for (int i = 0; i < n;i++){
                if(j  -nums[i] >=0){
                    dp[j] += dp[j - nums[i]];
                }
            }
        }
        return dp[target];
    }
};