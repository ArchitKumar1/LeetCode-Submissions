// https://leetcode.com/problems/number-of-longest-increasing-subsequence

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n+1,0);
        vector<int> cnt(n+1,0);
        
        dp[1] = 1;
        cnt[1] = 1;
        for(int i =1;i<=n;i++){
            for(int j = 1;j<i;j++){
                if(nums[i-1] > nums[j-1]){
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }else if(dp[i] == dp[j] +1){
                        cnt[i] += cnt[j];
                    }
                }
            }
        }
        int L = *max_element(dp.begin(),dp.end());
        int ans = 0;
        for(int i =1;i<=n;i++){
            if(dp[i] == L){
                ans += cnt[i];
            }
        }
        return ans;
        
                
        
    }
};