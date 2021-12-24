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
            unordered_set<int> st;
            for(int j = 0;j < n;j++){
                if( i >> j & 1){
                     st.insert(nums[j]);
                }
            }
            safe[i] = (st.size() == __builtin_popcount(i));
        }
        
        vector<int> dp(1<<n,1e9);
        dp[0] = 0;
        
        for(int i = 0;i < (1 << n) ;i++){

            int bits = __builtin_popcount(i);
            if(bits % m) continue;
            
            int turn = bits/m;
            if(turn == 1){
                if(safe[i]) {
                    // cout << bitset<4>(i) << " : " << turn << " " << dp[i] << " " << dp[0]<< endl;
                    dp[i] = min(dp[i] , dp[0] + is[i]);
                }
            }
            for(int s = i ; s; s = (s-1)&i){                

                int bitss = __builtin_popcount(s);
                if(bitss % m) continue;
                if((bits-bitss) != m) continue;
                // cout << bitset<4>(i-s) << " " << turn << " " << bitset<4>(i) << " " << bitset<4>(s) << endl;
                // cout << bitset<4>(i-s) << " " << safe[i-s] << endl;
                if(safe[i-s]) dp[i] = min(dp[i] , dp[s] + is[i-s]);
                // cout << bitset<4>(i-s) << " " << turn << " " << bitset<4>(i) << " " << bitset<4>(s) << endl;
                // cout << bitset<4>(i-s) << " " << safe[i-s] << endl;
                
            }
        }
        // for(int i = 0; i <= k;i++){
        //     for(int j = 0;j < 1 << n;j++){
        //         cout << bitset<4>(i) << " " << dp[i][j] << endl;
        //     }
        //     cout << endl;
        // }
        return dp.back() == 1e9 ? -1 : dp.back();
    }
};