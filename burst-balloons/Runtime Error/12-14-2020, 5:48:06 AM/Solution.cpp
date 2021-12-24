// https://leetcode.com/problems/burst-balloons

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        
        for(int i = n-1;i>=0;i--){
            for(int j = i;j<n;j++){
                for(int k = i;k<=j;k++){
                    int LR = (i>0?nums[i-1]:1)*(j<(n-1)?nums[j+1]:1);
                    dp[i][j] = max(dp[i][j], LR*nums[k] + (k>i?dp[i][k-1]:0) + (k<j?dp[k+1][j]:0));
                }
            }
        }
        
        return dp[0][n-1];
    }
};