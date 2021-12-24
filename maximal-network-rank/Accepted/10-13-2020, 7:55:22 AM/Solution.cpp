// https://leetcode.com/problems/maximal-network-rank

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<set<int>>G(n);
        vector<int> in(n);
        for(auto r : roads){
            int u = r[0],v=r[1];
            G[u].insert(v);
            G[v].insert(u);
            in[v]++,in[u]++;
        }
        int fans = 0;
        
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                
                int ans = in[i] + in[j] - (G[i].find(j)!= G[i].end());
                fans = max(fans,ans);
            }
            
        }
        return fans;
    }
};