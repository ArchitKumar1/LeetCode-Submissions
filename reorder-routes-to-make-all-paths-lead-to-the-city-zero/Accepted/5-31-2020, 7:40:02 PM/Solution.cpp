// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero

class Solution {
public:
    vector<vector<pair<int,int>>> G;
    int ans =0 ;

    void dfs(int s,int par){
        for(pair<int,int>  p : G[s]){
            bool pos = p.second;
            int c = p.first;
            
            if(c == par) continue;
            dfs(c,s);
            if(pos){ 
                ans++;
                // cout << s << " " << c << endl;
             }
        }
        
    }
    int minReorder(int n, vector<vector<int>>& e) {
        G.resize(n);
        for(vector<int> c : e){
            int u = c[0];
            int v = c[1];
            G[u].push_back({v,1});
            G[v].push_back({u,0});
        }
        dfs(0,-1);
        return ans;
    }
};