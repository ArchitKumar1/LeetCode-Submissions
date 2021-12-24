// https://leetcode.com/problems/satisfiability-of-equality-equations

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
    
    bool equationsPossible(vector<string>& equations) {
        dsu d(26);
        for(auto s : equations){
            int a = s[0] - 'a';
            int b = s.back() - 'a';
            if(s[1] == '='){
                d.merge(a,b);
            }
        }
        for(auto s : equations){
            int a = s[0] - 'a';
            int b = s.back() - 'a';
            if(s[1] == '!'){
                if(d.get(a)==d.get(b)) return 0;
            }
        }
        return 1;
    }
};