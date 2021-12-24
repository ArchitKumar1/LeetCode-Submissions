// https://leetcode.com/problems/count-ways-to-make-array-with-product

class Solution {
public:
    vector<int> waysToFillArray(vector  <vector<int>>& queries) {
        
        const int N = 12345;
        const int MOD =  1e9+7;
        
        auto pow_mod = [&](int a,int b,int m= MOD){
            long long res = 1;while(b){ if(b&1) res =((long long)res*a)%m; a = ((long long)a*a)%m;b >>=1;}return res;
        };
        vector<int> fact(N,1),ifact(N,1);
            
        for(int i = 1;i<N;i++){
            fact[i] = 1LL* fact[i-1] * i % MOD;
        }
        
        ifact[N-1] = pow_mod(fact[N-1],MOD-2,MOD);
            
        for(int i = N-2;i>=1;i--){
            ifact[i] = 1LL* ifact[i+1] * (i+1) % MOD;
        }
        auto factorize = [&](int x){
            vector<int> facts;
            int X = x;
            for(int i = 2;i*i<=X;i++){
                int cnt = 0;
                while(X%i == 0){
                    X/= i;
                    cnt++;
                }
                if(cnt > 0){
                    facts.push_back(cnt);
                }
            }
            if( X > 1) facts.push_back(1);
            return facts;
        };
        
        auto comb = [&](int n,int r){
            return 1LL* fact[n] * ifact[n-r] % MOD * ifact[r] % MOD;
        };
        vector<int> res;
        for(auto x : queries){
            int n = x[0],k = x[1];
            long long int total = 1;
            vector<int> facts = factorize(k);
            
            for(int f : facts){
                total = total * comb(n+f-1,n-1) % MOD;
            }
            res.push_back(total);
        }
        return res;
    }
};