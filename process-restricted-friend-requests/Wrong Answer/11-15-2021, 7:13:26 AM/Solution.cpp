// https://leetcode.com/problems/process-restricted-friend-requests

class Dsu {
    public:
    vector<int> par;
    int n;
    Dsu(){}
    Dsu(int _n) : n(_n) {
        par.resize(n);
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
            bool safe = true;
            for(auto re : restrictions){
                int x = re[0],y = re[1];
                if(d.get(u) == d.get(x) && d.get(v) == d.get(y)){
                    safe = false;
                }
            }
            ans.push_back(safe);
            if(safe) d.merge(u,v);
        }
        return ans;
    }
};