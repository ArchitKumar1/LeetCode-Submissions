// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
        
        vector<vector<pair<int,int>>> G1(n);
        
        for(auto x : connections ){
            int u = x[0],v = x[1];
            G1[u].push_back({v,1});
            G1[v].push_back({u,0});
        }
        int fans = 0;
        function<void(int,int)> dfs  = [&](int s,int par =-1) {
             for(auto c : G1[s]){
                 if(c.first != par){
                     dfs(c.first,s);
                     fans += c.second;
                 }
             }
        };
        dfs(0,-1);
        return fans;
    }
};