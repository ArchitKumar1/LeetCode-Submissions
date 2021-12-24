// https://leetcode.com/problems/minimum-incompatibility

class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        
        int n = nums.size();
        int m = n/k;
        
        vector<int> is(1 << n);
        for(int i = 0;i < 1 << n;i++){
            int mx = -1e9,mn = 1e9;
            for(int j = 0;j < n;j++){
                if( i >>j & 1){
                    mx = max(mx,nums[j]);
                    mn = min(mn,nums[j]);
                }      
            }
            is[i] = mx - mn;
        }
        vector<bool> safe(1 << n);
        for(int i = 0;i < 1 << n;i++){
            int ma = 0;
            bool sa = 1;
            for(int j = 0;j < n;j++){
                if( i >> j & 1){
                     if( ma >> nums[j] & 1){
                         sa = 0;
                         break;
                     }else{
                         ma |= (1 << nums[j]);
                     }
                }
            }
            safe[i] = sa;
        }
        vector<vector<int>> submasks(1 << n);
        for(int i = 0;i < 1 << n;i++){
            int bits = __builtin_popcount(i);
            submasks[bits].push_back(i);
        }
        
        vector<int> dp(1<<n,1e9);
        dp[0] = 0;
        
        for(int i = 1;i < (1 << n) ;i++){
            int bits = __builtin_popcount(i);
            if(bits % m) continue;
            // for(int s : submasks[bits-m]){
            //     if((i == (i|s)) && safe[i - s]) dp[i] = min(dp[i] , dp[s] + is[i-s]);
            // }
            if(bits == m){
                if(safe[i]) dp[i] = min(dp[i] ,is[i]);
            }
            for(int s = i;s;s=(s-1)&i){
                int bits2 = __builtin_popcount(s);
                if((bits - bits2) == m && safe[i - s]) dp[i] = min(dp[i] , dp[s] + is[i-s]);
            }
        }
        return dp.back() >= 1e9 ? -1 : dp.back();
    }
};