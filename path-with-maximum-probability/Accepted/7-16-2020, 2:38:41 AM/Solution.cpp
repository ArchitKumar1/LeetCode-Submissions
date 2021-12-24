// https://leetcode.com/problems/path-with-maximum-probability

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<pair<int,double>>> G(n);
        int pos = 0;
        for(auto x : edges){
            int u = x[0];
            int v = x[1];
            double d = succProb[pos++];
            G[u].emplace_back(v,d);
            G[v].emplace_back(u,d);
        }
        vector<int> vis(n,0);
        vector<double> dist(n,0);
        
        
        dist[start] = 1;
        
        priority_queue<pair<double,int>> s;
        s.push({1,start});
        
        while(s.size()){
            
            auto [d,u] = s.top();
            s.pop();
            
            if(vis[u] == 1) continue;
            vis[u] = 1;
            
            for(auto p : G[u]){
                if(dist[p.first] < dist[u]*p.second){
                    s.push({dist[p.first] = dist[u]*p.second,p.first});
                }
            }
        }
        return dist[end];
        

        
    }
};