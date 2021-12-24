// https://leetcode.com/problems/maximize-score-after-n-operations

class Solution {
public:
    int maxScore(vector<int>& nums) {
        
        int ans = 0;
        int n = nums.size();
        vector<vector<int>> dp(1<<n,vector<int>(n,0));
        for(int m =0;m<1<<n;m++){
            int bits = __builtin_popcount(m);
            if(bits % 2) continue;
            int ops =bits/2;
            for(int i = 0;i < n;i++){
                for(int j = i+1;j<n;j++){
                    if(m>>i&1 && m>>j&1){
                        int nm = m^(1<<i)^(1<<j);
                        dp[m][ops] = max(dp[m][ops],dp[nm][ops-1] + ops*__gcd(nums[i],nums[j]));
                        ans = max(ans,dp[m][ops]);
                    }
                }
            }
        }
        return ans;
        
    }
};