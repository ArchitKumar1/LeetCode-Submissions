// https://leetcode.com/problems/graph-connectivity-with-threshold

class dsu {
    public:
    vector<int> par;
    int n;
    dsu(int _n) : n(_n) {
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
    
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        dsu d = dsu(n+1);
        
        for(int i = threshold+1;i<=n;i++){
            for(int j = i;j<=n;j+=i){
                d.merge(i,j);
            }
        }
        int q = queries.size();
        
        vector<bool> res(q);
        for(int i = 0;i<q;i++){
            int a = queries[i][0];
            int b = queries[i][1];
            res[i]= d.get(a)==d.get(b);
        }
        return res;
    }
};