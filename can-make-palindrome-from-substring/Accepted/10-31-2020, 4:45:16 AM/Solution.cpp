// https://leetcode.com/problems/can-make-palindrome-from-substring


#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& q) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = s.size();
        
        int dp[n+1];
        
        memset(dp,0,sizeof(dp));
        
        for(int i = 1;i<=n;i++){
            dp[i] ^= (1 << (s[i-1] -'a'));
            dp[i] ^= dp[i-1];
        }
        
        int m = q.size();
        vector<bool> ans(m);
        
        for(int i= 0 ;i<m;i++){
            int l = q[i][0],r = q[i][1],k = q[i][2];
            int o = __builtin_popcount(dp[r+1] ^ dp[l]);
            if(o/2 <= k){
                ans[i] = 1;
            }
            
        }
        return ans;
    }
};