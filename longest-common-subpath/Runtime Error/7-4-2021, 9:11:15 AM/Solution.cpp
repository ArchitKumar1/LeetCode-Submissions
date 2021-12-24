// https://leetcode.com/problems/longest-common-subpath

class dsu {
    public:
    vector<int> par;
    vector<int> size;
    int n;
    bool done = 0;
    dsu(int _n) : n(_n) {
        par.resize(n);
        size.assign(n,0);
        iota(par.begin(), par.end(), 0);
    } 
    inline int get(int x) {
        return (x == par[x] ? x : (par[x] = get(par[x])));
    }
    inline bool merge(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            par[x] = y;
            size[y] += (size[x]+1);
            done = true;
            return true;
        }else{
            size[x]++;
        }
        return false;
    }
};
class Solution {
public:
    vector<multiset<int>> G;
    vector<int> vis;
    vector<int> dp;
    vector<multiset<int>> in;
    int ans = 0;
    
    void dfs(int s,int val = 1){
        ans = max(ans,val);
        for(int c : G[s]){
            if(vis[c] == 0){
                G[s].erase(G[s].find(c));
                dfs(c,val+1);
            }
            dp[s] = max(dp[s],dp[c] + 1);
        }  
    }
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        map<pair<int,int>,set<int>> m1;
        map<int,set<int>> m2;
        int pos = 0;
        for(auto path : paths){
            for(int j = 0;j+1 < path.size();j++){
                m1[{path[j],path[j+1]}].insert(pos);
            }
            for(int j = 0;j< path.size();j++){
                m2[path[j]].insert(pos);
            }
            pos++;
        }
        vector<pair<int,int>> v;
        for(auto x : m1){
            cout << x.first.first << " " <<x.first.second << " " << x.second.size() << endl;
            if(x.second.size() == paths.size()){
                v.push_back(x.first);
            }
        }
        
        // dsu d(n);
        // for(auto x: v){
        //     int u = x.first,v = x.second;
        //     bool ans = d.merge(u,v);
        //     cout << u << " v " << v << " " << ans << endl;
        // }
        
//         int ans = 0;
        
//         for(int i= 0;i < n;i++){
//             cout << i << " :  " << d.get(i) << " " << d.size[d.get(i)] << endl;
//             ans = max(ans,d.size[d.get(i)]);
//         }
//         cout << endl;
//         cout << single << endl;
//         return ans + (single);
        
        G.resize(n);
        vis.assign(n,0);
        dp.assign(n,0);
        in.resize(n);
        bool single = 0;
        for(auto x : m2){
            if(x.second.size() == paths.size()){
                dp[x.first] = 1;
                single = 1;
            }
        }
        for(auto x: v){
            int u = x.first,v = x.second;
            dp[u] = 1;
            dp[v] = 1;
            in[v].insert(u);
            G[u].insert(v);
        }
        
        for(int i = 0;i < n;i++){
            if(!vis[i]) dfs(i);
        }
        
        cout << endl;
        return *max_element(dp.begin(),dp.end());
        
    }
};