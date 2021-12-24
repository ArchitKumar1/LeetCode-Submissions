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
            for(int j : vector<int>{0,1,2}){
                if(nums[i] == j){
                    ndp[j+1] += dp[j];
                    ndp[j+1] %= M;
                    ndp[j+1] += dp[j+1];
                    ndp[j+1] %= M;
                }
            }
            
            swap(dp,ndp);
        }
        return dp.back();
        
    }
};