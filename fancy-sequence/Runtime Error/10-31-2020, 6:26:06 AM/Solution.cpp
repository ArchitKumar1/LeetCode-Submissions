// https://leetcode.com/problems/fancy-sequence

class Fancy {
    private:
    const int mod = 1e9+7;
    #define LL long long int
    
public:
    
    int pow_mod(LL a,LL b){
        if(b == 0) return 1;
        LL res = 1;
        if(b%2 == 1){
            res *= a;
            res %= mod;
        }
        res *= pow_mod(a*a%mod,b/2);
        res %= mod;
        return res;
    }
    
    vector<LL> vals = {0};
    vector<pair<LL,LL>> mas = {{1,0}};
    
    Fancy() {
        
    }
    
    void append(int val) {
        vals.push_back(val);
        mas.push_back(mas.back());
    }
    
    void addAll(int inc) {
       (mas.back().second += inc)%=mod;
    
    }
    
    void multAll(int m) {
        (mas.back().first *= m)%=mod;
        (mas.back().second *= m)%=mod;
    }
    
    int getIndex(int idx) {
        int n = vals.size();
        if(idx >= vals.size()){
            return -1;
        }
        int mul = mas.back().first*pow_mod(mas[idx].first,mod-2);
        int sum = (mod + mas.back().second - mas[idx].second*mul%mod)%mod;
        assert(idx+1<vals.size());
        return (vals[idx+1]*mul + sum)%mod;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */