// https://leetcode.com/problems/path-with-minimum-effort

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size();
        int m = h.front().size();
        
        auto safe = [&](int i,int j){
            return i>=0 && j>=0 && i <n && j<m;
        };
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        
        vector<vector<pair<int,int>>> G(n*m);
        for(int i = 0 ;i<n;i++){
            for(int j = 0;j<m;j++){
                for(int k = 0;k<4;k++){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(safe(x,y)){
                        G[m*i + j].push_back({m*x + y,abs(h[i][j]-h[x][y])});
                    }
                }
            }
        }
        vector<int> vis(n*m,0);
        vector<int> dist(n*m,1e9);
        dist[0] = 0;
        priority_queue<pair<int,int> ,vector<pair<int,int>> ,greater<pair<int,int>>> pq;
        pq.push({0,0});
        
        while(pq.size()){
            auto[x,p] = pq.top();pq.pop();
            if(vis[p] == 1) continue;
            vis[p] = 1;
            for(auto[q,d] : G[p]){
                if(dist[q] > max(x,d)){
                    dist[q] =  max(x,d);
                    pq.push({dist[q],q});
                }
            }
        }
        // for(int i = 0 ;i<n;i++){
        //     for(int j = 0;j<m;j++){
        //         cout << dist[m*i+j] << " ";
        //     }
        //     cout << endl;
        // }
        return dist[n*m-1];
    }
};