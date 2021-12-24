// https://leetcode.com/problems/parallel-courses-iii

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> G(n);
        vector<vector<int>> IG(n);
        
        for(auto x : relations){
            x[0]--;x[1]--;
            G[x[0]].push_back(x[1]);
            IG[x[1]].push_back(x[0]);
        }
        vector<int> vis(n);
        vector<int> topo; topo.reserve(n);
        
        function<void(int)> dfs = [&](int s){
            vis[s] = 1;
            for(int c : G[s]) {
                if(!vis[c]) dfs(c);
            }
            topo.push_back(s);
        };
        dfs(0);
        for(int i = 0;i < n;i++){
            if(!vis[i]) dfs(i);
        }
        reverse(topo.begin(),topo.end());
        vector<int> dp(n,0);
        dp[0] = 0;
        for(int i = 0; i < n;i++){
            if(IG[i].size() == 0){
                dp[i] = time[i];
            }
            // cout << i << endl;
            for(int par : IG[i]){
                // cout << i << " " << par << endl;
                dp[i] = max(dp[i] , time[i] + dp[par]);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};