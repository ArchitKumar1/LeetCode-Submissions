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
        
        set<pair<double,int>> s;
        s.insert({1,start});
        
        while(s.size()){
            
            auto [d,u] = *s.begin();
            cout <<d << " " << u << endl;
            s.erase(s.begin());
            
            if(vis[u] == 1) continue;
            vis[u] = 1;
            
            for(auto p : G[u]){
                cout << "P " << p.first << " " << p.second << endl;
                if(dist[p.first] < dist[u]*p.second){
                    s.insert({dist[p.first] = dist[u]*p.second,p.first});
                }
            }
        }
        for(int i=0;i< n;i++){
            cout << dist[i] << " ";
        }
        return dist[end];
        

        
    }
};