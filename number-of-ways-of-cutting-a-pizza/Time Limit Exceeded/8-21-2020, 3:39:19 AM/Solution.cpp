// https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza

class Solution {

public:
    int dp[51][51][11];
    int cnt[55][55];
    int mod = 1e9+7;
    
    int n,m;

    int solve(int x1,int y1,int k){
        if(cnt[x1][y1] == 0) return 0;
        if(k == 0) return 1;
        
        int ans = 0;
        for(int K = y1+1;K<=m;K++){
            if(cnt[x1][y1] - cnt[x1][K] > 0){
                ans += solve(x1,K,k-1);
            }
        }
        for(int K = x1+1;K<=n;K++){
            if(cnt[x1][y1] - cnt[K][y1]  > 0){
                ans += solve(K,y1,k-1);
            }
        }
        return ans;
    }
    int ways(vector<string>& pizza, int k) {
        n = pizza.size();
        m = pizza[0].size();
        
        memset(cnt,sizeof(cnt),0);
        for(int i = n;i>=1;i--){
            for(int j = m;j>=1;j--){
                cnt[i][j] = (pizza[i-1][j-1]=='A') + cnt[i+1][j] + cnt[i][j+1] - cnt[i+1][j+1];
            }
        }
        return solve(1,1,k-1);
    
        
    }
};