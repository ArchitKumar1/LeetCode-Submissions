// https://leetcode.com/problems/maximum-ascending-subarray-sum

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n+1);
        
        dp[0] = nums[0];
        for(int i = 1;i<n;i++){
            dp[i] = nums[i];
            if(nums[i] > nums[i-1]){
                dp[i] = dp[i-1] + nums[i];
            }
            
            
        }
        return *max_element(dp.begin(),dp.end());
    }
};