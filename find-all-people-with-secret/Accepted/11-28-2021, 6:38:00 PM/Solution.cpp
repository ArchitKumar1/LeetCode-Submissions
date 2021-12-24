// https://leetcode.com/problems/find-all-people-with-secret

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>&m, int f) {
        vector<int> sec(n);
        sec[0] = 1;
        sec[f] = 1;
        int mxt = 0;
        for(auto x : m) mxt = max(mxt ,x[2]);
        mxt += 1;
        vector<pair<int,int>> G[mxt];
        for(auto x : m) G[x[2]].push_back({x[0],x[1]});

        for(int i = 0; i < mxt;i++){
            map<int,vector<int>> m1;
            vector<int> starts;
            for(auto[u,v] : G[i]){
                starts.push_back(u);
                starts.push_back(v);
                m1[u].push_back(v); 
                m1[v].push_back(u); 
            }
            unordered_map<int,int> vis;
            bool hasOne = false;
            function<void(int)> dfs = [&](int s){
                if(vis[s]) return;
                vis[s] = 1;
                if(sec[s] == 1) hasOne = true;
                for(int c : m1[s]){
                    dfs(c);
                }
            };
            function<void(int)> dfs2 = [&](int s){
                if(vis[s]) return;
                vis[s] = 1;
                sec[s] = 1;
                for(int c : m1[s]){
                    dfs2(c);
                }
            };
            for(int s : starts){
                if(!vis[s]){
                    hasOne = false;
                    dfs(s);
                    vis.clear();
                    if(hasOne){
                        dfs2(s);
                    }
                }
            }
        }
        vector<int> ans;
        for(int i = 0;i < n;i++) if(sec[i] == 1) ans.push_back(i);
        return ans;
    }
};