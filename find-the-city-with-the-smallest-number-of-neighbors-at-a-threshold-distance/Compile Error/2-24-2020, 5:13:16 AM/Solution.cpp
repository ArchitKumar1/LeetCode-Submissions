// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance

class Solution {
public:
    vector<vector<pair<int,int>>> G;
    int T;
    int N;
    int mc = INT_MAX;
    vector<int> fans;
    void dij(int st){
        vector<int> vis(N+1,0);
        vector<int> dist(N+1,1e9);
        set<pair<int,int>> ss;
        
        ss.insert({0,st});
        while(ss.size()){
            pair<int,int> top = *ss.begin();
            ss.erase(ss.begin());
            int u = top.second;
            if(vis[u] == 1) continue;
            vis[u] = 1;
            for(pair<int,int> p :G[u]){
                int v = p.first;
                int d = p.second;
                if(dist[v] > dist[u] + d){
                    ss.insert({dist[v] = dist[u] + d,v});
                }
            }
        }
        cout << st << endl;
        for(int i = 0;i<n;i++){
            cout << dist[i] << " ";
            
        }
        cout << endl;
        int cnt = 0;
        for(int i = 0;i<N;i++){
            if(i!=st){
                if(dist[i] <= T){
                    cnt += 1;
                }
            }
        }
        if(cnt == mc){
            fans.push_back(st);
        }
        if(cnt < mc){
            mc= cnt;
            fans.clear();
            fans.push_back(st);
        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int t) {
        T = t;
        N = n;
        G.resize(n);
        for(auto v : edges){
            int x = v[0];
            int y = v[1];
            int d = v[2];
            G[x].emplace_back(y,d);
            G[y].emplace_back(x,d);
        }
        for(int i =0 ;i<n;i++){
            dij(i);
        }
        return *max_element(fans.begin(),fans.end());
    }
};