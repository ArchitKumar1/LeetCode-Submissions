// https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza

class Solution {

public:
    int dp[51][51][51][51];
    int cnt[55][55];
    int mod = 1e9+7;
    map<vector<int>,int> m1;
    
    int n,m;
    int getcnt(int x1,int y1,int x2,int y2){
            x2++;x1++;y1++;y2++;
            return cnt[x2][y2] - cnt[x2][y1-1] - cnt[x1-1][y2] + cnt[x1-1][y1-1];
    }

    int solve(int x1,int y1,int x2,int y2,int k){
        if(m1.find(vector<int>{x1,y1,x2,y2,k}) !=m1.end())
            return m1[vector<int>{x1,y1,x2,y2,k}] ;
        
        if(getcnt(x1,y1,x2,y2) == 0) return 0;
        if(k == 0){
            return getcnt(x1,y1,x2,y2) > 0;
        }
        
        int ans = 0;
        for(int K = y1;K<y2;K++){
            if(getcnt(x1,y1,x2,K)>=1){
                 (ans +=  solve(x1,K+1,x2,y2,k-1))%=mod;
            }
        }
        for(int K = x1;K<x2;K++){
            if(getcnt(x1,y1,K,y2)>=1) {
                (ans += solve(K+1,y1,x2,y2,k-1))%=mod;
            }
        }
        return   m1[vector<int>{x1,y1,x2,y2,k}] = ans;
    }
    int ways(vector<string>& pizza, int k) {
        n = pizza.size();
        m = pizza[0].size();
        
        memset(cnt,sizeof(cnt),0);
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                cnt[i][j] = (pizza[i-1][j-1]=='A') + cnt[i-1][j] + cnt[i][j-1] - cnt[i-1][j-1];
            }
        }
        return solve(0,0,n-1,m-1,k-1);
    
        
    }
};