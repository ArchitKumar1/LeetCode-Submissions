// https://leetcode.com/problems/combination-sum-iv

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        long long n=  nums.size();
        
        long long dp[target + 2] = {0};
        dp[0] = 1;
        for (long long j = 1; j <= target;j++){
            for (long long i = 0; i < n;i++){
                if(j  -nums[i] >=0){
                    dp[j] += dp[j - nums[i]];
                }
            }
        }
        return dp[target];
    }
};