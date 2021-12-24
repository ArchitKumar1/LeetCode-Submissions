// https://leetcode.com/problems/the-time-when-the-network-becomes-idle

template<typename T>  using min_pq = priority_queue<T,vector<T>,greater<T>>;
class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        int m = edges.size();
        
        vector<vector<int>> G(n);
        for(auto e : edges){
            int u = e[0],v = e[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vector<int> dist(n,1e9);
        dist[0] = 0;
        min_pq<pair<int,int>> pq;
        pq.emplace(0,0);
        while(pq.size()){
            auto[d,u] = pq.top(); pq.pop();
            for(int v : G[u]){
                if(dist[v] > dist[u] + 1){
                    dist[v] = dist[u] + 1;
                    pq.emplace(dist[v],v);
                }
            }
        }
        int ans = 0;
        for(int i = 1;i < n;i++){
            int roundtrip = 2 * dist[i];
            int rem = roundtrip % patience[i];
            int last = -1;
            if(rem > 0){
                last = roundtrip - rem;
            }else{
                last = roundtrip - patience[i];
            }
            last += roundtrip;
            ans = max(last,ans);
        }
        return ans + 1;
        // 0 5 10
        // patience = 3 
        // 0 3 6 9 
        // // closest point till message return + round trip
    }
};