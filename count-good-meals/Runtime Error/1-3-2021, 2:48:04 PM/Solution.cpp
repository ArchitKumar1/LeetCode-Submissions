// https://leetcode.com/problems/count-good-meals

class Solution {
public:
    int mod = 1e9+7;
    template <class T,class U>
        T pow_mod(T a,U b,int mod){long long  res = 1;while(b){ if(b&1) res =((long long)res*a)%mod; a = ((long long)a*a)%mod;b >>=1;}return res;}

    int countPairs(vector<int>& deliciousness) {
        long long int ans = 0;
        
        unordered_map<long long,long long> m1;
        for(int c : deliciousness){
            m1[c]++;
        }
        long long int f = 0;
        map<int,int> m2;
        for(int c : deliciousness){
            if(m2[c]) continue;
            m2[c]++;
            for(int i = 0;i<=21;i++){
                int L = (1<<i) - c;
                int C;
                if(2*c == (1<<i)){
                    C = m1[c];
                    f += C*(C-1)/2;
                    
                }else{
                    ans += m1[c]*m1[L];
                }
                ans %= mod;
                
            }
        }
        cout << f+ans/2  << endl;
        return (f + ans*pow_mod(2,mod-2,mod)%mod)%mod;
    }
};