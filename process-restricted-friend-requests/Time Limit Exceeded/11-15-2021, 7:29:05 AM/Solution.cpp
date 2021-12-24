// https://leetcode.com/problems/process-restricted-friend-requests

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
            int u = d.get(r[0]),v = d.get(r[1]);
            if(u == v){
                ans.push_back(true);
                continue;
            }
            bool safe = true;
            for(auto re : restrictions){
                int x = d.get(re[0]);
                int y = d.get(re[1]);
                if((u == x && v == y) || (u == y && v == x)){
                    safe = false;
                }
            }
            ans.push_back(safe);
            if(safe) d.merge(u,v);
        }
        return ans;
    }
};