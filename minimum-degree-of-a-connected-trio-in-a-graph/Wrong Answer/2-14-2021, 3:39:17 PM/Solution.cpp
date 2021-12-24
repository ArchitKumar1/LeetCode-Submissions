// https://leetcode.com/problems/minimum-degree-of-a-connected-trio-in-a-graph

class Solution {
public:
    
    
    
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> G(n,vector<int>(n,0));
        vector<int> deg(n);
        for(auto x : edges){
            int u = x[0],v = x[1];u--,v--;
            deg[u]++,deg[v]++;
            G[u][v] = 1,G[v][u] =1;
        }
        int ans = INT_MAX;
        for(int i = 0;i<n;i++){
            for(int j= i+1;j<n;j++){
                for(int k = j+1;k<n;k++){
                    if(G[i][j]&&G[j][k]&&G[k][i]){
                        ans = min(ans,deg[i]+deg[j]+deg[k]-6);
                    }
                }
            }
        }
        return ans;
        
        
        
    }
};