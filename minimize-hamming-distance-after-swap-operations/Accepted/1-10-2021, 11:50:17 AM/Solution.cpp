// https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations

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
    
    
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        
        int n = source.size();
        
        dsu D(n);
        
        for(auto x : allowedSwaps){
            D.merge(x[0],x[1]);
        }
        int fans = 0;
        vector<vector<pair<int,int>>> G1(n);
        for(int i = 0;i<n;i++){
            int par = D.get(i);
            G1[par].emplace_back(source[i],i);
        }
        
        for(auto x : G1){
            multiset<int> F,S;
            for(auto p : x){
                F.insert(p.first);
                S.insert(target[p.second]);
            }
            for(auto it : S){
                if(F.find(it) == F.end()){
                    fans += 1;
                }else{
                    F.erase(F.find(it));
                }
            }
        }
        return fans;
    }
};