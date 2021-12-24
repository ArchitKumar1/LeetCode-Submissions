// https://leetcode.com/problems/can-make-palindrome-from-substring

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& q) {
        int n = s.size();
        
        int dp[n+1][26];
        
        memset(dp,0,sizeof(dp));
        
        for(int i = 1;i<=n;i++){
            for(int j = 0;j<26;j++){
                int c = s[i-1] - 'a';
                if(c == j){
                    dp[i][j] += 1;
                }
                dp[i][j] += dp[i-1][j];
            }
        }
        
        int m = q.size();
        vector<bool> ans(m);
        
        for(int i= 0 ;i<m;i++){
            int l = q[i][0],r = q[i][1],k = q[i][2];
            int o = 0,e = 0;
            for(int j= 0;j<26;j++){
                if((dp[r+1][j] - dp[l][j])%2 == 1)o++;
            }
            if(o/2 <= k){
                ans[i] = 1;
            }
            
        }
        return ans;
    }
};