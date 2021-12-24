// https://leetcode.com/problems/count-number-of-special-subsequences

class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(4);
        dp[0] = 1;
        int ans = 0;
        int M = 1e9 + 7;
        for(int i = 0;i <n;i++){
            vector<int> ndp = dp;
            if(nums[i] == (1-1)) ndp[1] += dp[0],ndp[1]+= dp[1],ndp[1] %= M;
            if(nums[i] == (2-1)) ndp[2] += dp[1],ndp[2]+= dp[2],ndp[2] %= M;
            if(nums[i] == (3-1)) ndp[3] += dp[2],ndp[3]+= dp[3],ndp[3] %= M;
            
            swap(dp,ndp);
        }
        
        return dp.back();
        
    }
};