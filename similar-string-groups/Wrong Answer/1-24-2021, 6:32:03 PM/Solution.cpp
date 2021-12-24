// https://leetcode.com/problems/similar-string-groups

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
    
    bool same(string s,string t){
        int cnt = 0;
        for(int i = 0;i<s.size();i++){
            cnt += (s[i] != t[i]);
        }
        return (cnt == 2 || cnt == 0);
    }
    
    
    int numSimilarGroups(vector<string>& strs) {
        
        int n = strs.size();
        const int N = 1e3+5;
        
        dsu D(N);
        
        for(int i = 0;i+1<n;i++){
            for(int j = 0;j<n;j++){
                if(same(strs[i],strs[i+1])){
                    cout << i << " "<< i+1 << " " << D.merge(i,i+1) << endl;
                }
            }
        }
        set<int> s;
        for(int i = 0;i<n;i++){
            s.insert(D.get(i));
        }
        return s.size();
    }
};