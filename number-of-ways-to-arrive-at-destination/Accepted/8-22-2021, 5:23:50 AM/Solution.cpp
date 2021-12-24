// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination


class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<long long>> dp(n,vector<long long>(n,1e18));
        vector<vector<pair<int,int>>> G(n);

        for(auto x : roads){
            int u = x[0],v = x[1],d = x[2];
            dp[u][v] = d,dp[v][u] = d;
            G[u].emplace_back(v,d);
            G[v].emplace_back(u,d);
        }
        for(int i = 0;i < n;i++) dp[i][i] = 0LL;
        for(int k = 0;k < n;k ++){
            for(int i = 0;i < n;i ++){
                for(int j = 0;j < n;j ++){
                    if(dp[i][j] > dp[i][k] + dp[k][j]){
                        dp[i][j] = dp[i][k] + dp[k][j];
                    }
                }
            }
        }
        
        vector<pair<long long,int>> vp;
        for(int i = 0;i < n;i++){
            vp.emplace_back(dp[0][i],i);
        }
        sort(vp.begin(),vp.end());
        vector<int> ans(n,0);
        ans[0] = 1;
        
        for(int i = 0;i < n;i++){
            int u = vp[i].second;
            // cout << vp[i].first << " " << vp[i].second << endl;
            for(auto[v,d] : G[u]){
                if(dp[0][u] == dp[0][v] + d){
                    ans[u] += ans[v];
                    ans[u] %= (int)(1e9 + 7);
                }
            }
        }
        // for(int i = 0;i < n;i++){
        //     cout << ans[i] << " ";
        // }
        cout << endl;
        return ans[n-1];
    }
};