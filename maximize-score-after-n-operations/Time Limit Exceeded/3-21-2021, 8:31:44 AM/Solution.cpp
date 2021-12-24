// https://leetcode.com/problems/maximize-score-after-n-operations

class Solution {
public:
    int maxScore(vector<int>& nums) {
        
        int n = nums.size();
        int OP = n/2;
        int dp[1 << n][OP+1];
        memset(dp,0,sizeof(dp));
        for(int op = 1;op <= OP;op++ ){
            for(int m = 0;m < 1 << n;m++){
                dp[m][op] = max(dp[m][op],dp[m][op-1]);
                int bits = __builtin_popcount(m);
                if(bits < 2) continue;
                for(int i = 0;i< n;i++){
                    for(int j = i+1;j<n;j++){
                        if( m>>i&1 && m>>j&1){
                            int nm = m ^ (1 << i) ^ (1 << j);
                            dp[m][op] = max(dp[m][op],dp[nm][op-1] + op*__gcd(nums[i],nums[j]));
                        }
                    }
                }
            }
        }
        return dp[-1 + (1 << n)][OP];
    }
};