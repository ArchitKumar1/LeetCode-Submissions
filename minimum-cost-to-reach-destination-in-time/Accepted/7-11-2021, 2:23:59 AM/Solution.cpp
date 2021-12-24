// https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time



class Solution {
public:
    int n;
    vector<vector<pair<int,int>>> G;
    
    
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& ps) {
        int n = ps.size();
        G.resize(n);
        for(auto e: edges){
            G[e[0]].emplace_back(e[1],e[2]);
            G[e[1]].emplace_back(e[0],e[2]);
        }
        vector<vector<int>>dp(1001,vector<int>(1001,1e9));
        dp[0][0] = ps[0];
        
        for(int t=0;t<=maxTime;t++){
            for(int j = 0;j<n;j++){
                if(dp[j][t] == 1e9) continue;
                for(auto[k,c] : G[j]){
                    int nt = c + t;
                    if(nt <= maxTime){
                        dp[k][nt] = min(dp[k][nt],dp[j][t] + ps[k]);
                    }
                }
            }
        }
        int ans = *min_element(dp[n-1].begin(),dp[n-1].end());
        return ans == 1e9 ? -1 :ans;
    }
};