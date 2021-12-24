// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int c : nums) sum += c;
        if(sum&1)return 0;
        int tobe = sum/2;
        
        int n = nums.size();
        int dp[n+1][tobe+1];
        memset(dp,0,sizeof(dp));
        
        dp[0][0] = 1;
        
        for(int i = 1;i<=n;i++){
            for(int j = 0;j<=tobe;j++){
                dp[i][j] |= dp[i-1][j];
                if(j+nums[i-1] <=tobe) dp[i][j+nums[i-1]] |= dp[i-1][j];
            }
        }
        return dp[n][tobe];
    }
};