// https://leetcode.com/problems/process-restricted-friend-requests

class Dsu {
    public:
    vector<int> par;
    vector<int> sz;
    int n;
    Dsu(){}
    Dsu(int _n) : n(_n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        sz.assign(n,1);
    } 
    inline int get(int x) {
        return (x == par[x] ? x : (par[x] = get(par[x])));
    }
    inline bool merge(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            par[x] = y;
            sz[y] += sz[x];
            return true;
        }
        return false;
    }
};

class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        Dsu d(n);
        vector<bool> ans;
        ans.reserve(n);
        for(auto r : requests){
            int u = r[0],v = r[1];
            if(d.get(u) == d.get(v)){
                ans.push_back(true);
                continue;
            }
            bool safe = true;
            for(auto re : restrictions){
                int x = re[0],y = re[1];
                if((d.get(u) == d.get(x) && d.get(v) == d.get(y)) || 
                   (d.get(u) == d.get(y) && d.get(v) == d.get(x) )){
                // if(d.get(u) == x && d.get(v) == y){
                    safe = false;
                }
            }
            ans.push_back(safe);
            if(safe) d.merge(u,v);
        }
        return ans;
    }
};