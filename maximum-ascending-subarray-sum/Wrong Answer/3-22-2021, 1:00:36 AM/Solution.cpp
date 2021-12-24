// https://leetcode.com/problems/maximum-ascending-subarray-sum

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n+1);
        
        
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<i;j++){
                dp[i] = nums[i];
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i],nums[i] + dp[j]);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};