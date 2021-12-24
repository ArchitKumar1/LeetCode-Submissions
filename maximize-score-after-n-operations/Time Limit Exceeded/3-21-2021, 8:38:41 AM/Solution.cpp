// https://leetcode.com/problems/maximize-score-after-n-operations

class Solution {
public:
    int maxScore(vector<int>& nums) {
        
        int n = nums.size();
        int OP = n/2;
        int dp[1 << n][OP+1];
        memset(dp,0,sizeof(dp));
        
        vector<int> bit[1 << n];
        for(int m = 0;m < 1 << n;m++){
            bit[m].reserve(n);
            for(int i = 0;i<n;i++){
                if(m>>i&1){
                    bit[m].push_back(i);
                }
            }
        }
        for(int op = 1;op <= OP;op++ ){
            for(int m = 0;m < 1 << n;m++){
                dp[m][op] = max(dp[m][op],dp[m][op-1]);
                int bits = __builtin_popcount(m);
                if(bits < 2) continue;
                for(int x = 0;x< bit[m].size();x++){
                    for(int y = x+1;y<bit[m].size();y++){
                        int i = bit[m][x],j = bit[m][y];
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