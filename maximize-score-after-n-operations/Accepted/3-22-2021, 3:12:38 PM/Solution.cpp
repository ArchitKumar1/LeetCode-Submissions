// https://leetcode.com/problems/maximize-score-after-n-operations

class Solution {
public:
    int maxScore(vector<int>& nums) {
        
        int n = nums.size();
        int OP = n/2;
        int dp[1 << n];
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
        int GCD[n][n];
        for(int x = 0;x< n;x++){
            for(int y = 0;y<n;y++){
                GCD[x][y] = __gcd(nums[x],nums[y]);
            }
        }
        
        for(int m = 0;m < 1 << n;m++){
            dp[m] = max(dp[m],dp[m]);
            int bits = __builtin_popcount(m);
            if(bits < 2 || bits%2 == 1) continue;
            
            int op = bits/2;
            for(int x = 0;x< bit[m].size();x++){
                for(int y = x+1;y<bit[m].size();y++){
                    int i = bit[m][x],j = bit[m][y];
                    if( m>>i&1 && m>>j&1){
                        int nm = m ^ (1 << i) ^ (1 << j);
                        dp[m] = max(dp[m],dp[nm]+ op*GCD[i][j]);
                    }
                }
            }
        }
        
        return dp[-1 + (1 << n)];
    }
};