// https://leetcode.com/problems/valid-arrangement-of-pairs

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,int> atu , uta;
        const int N = 1e5 + 1;
        int timer = 0;
        int M = pairs.size();
        
        auto getU = [&](int a){
            if(atu.find(a)!=atu.end()) return atu[a];
            else{
                atu[a] = timer;
                uta[timer] = a;
                timer++;
                return atu[a];
            }
        };
        vector<pair<int,int>> E(M);
        vector<int> G[N];
        vector<int> in(N),out(N);
        vector<int> vis(N);
        for(int i = 0;i < M;i++){
            vector<int> p = pairs[i];
            int u = p[0],v = p[1];
            u = getU(u);
            v = getU(v);
            // cout << u << " " << v << endl;
            // cout << u << ": " << uta[u] << endl;
            // cout << v << ": " << uta[v] << endl;
            G[u].push_back(i);
            out[u]++,in[v]++;
            E[i].first = u;
            E[i].second = v;
        }
        int s = 0;
        for(int i = 0;i < N;i++){
            if((out[i]-in[i]) == 1) s = i;
        }
        vector<int> res;
        function<void(int)> dfs = [&](int s){
            while(G[s].size()){
                int e = G[s].back();
                G[s].pop_back();
                if(vis[e] == 1){
                    continue;
                }
                vis[e] = 1;
                dfs(E[e].second^E[e].first^s);
            }
            res.push_back(s);
        };
        dfs(s);
        vector<vector<int>> ans;
        reverse(res.begin(),res.end());
        for(int i = 1;i < res.size();i++){
            ans.push_back({uta[res[i-1]],uta[res[i]]});
        }
        return ans;
        
    }
};