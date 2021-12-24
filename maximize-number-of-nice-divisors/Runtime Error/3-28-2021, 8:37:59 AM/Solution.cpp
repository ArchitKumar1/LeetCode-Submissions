// https://leetcode.com/problems/maximize-number-of-nice-divisors

const int MOD = 1e9+7;
template <class T>T pow_mod(T a,T b,int m= MOD){long long  res = 1;while(b){ if(b&1) res =((long long)res*a)%m; a = ((long long)a*a)%m;b >>=1;}return res;}
class Solution {
    

public:
    int maxNiceDivisors(int primeFactors) {
        
        int q = primeFactors/3;
        int r = primeFactors%3;
        int ans = 1;
        if(r  == 0){
            ans = pow_mod(3,q,MOD);
        }else if(r == 1){
            ans = q>0 ? pow_mod(3,q-1,MOD) : 1;
            ans = ans*(q> 0 ? 4 : 1)% MOD;
        }else if(r == 2){
            ans = pow_mod(3,q,MOD);
            ans = ans*2% MOD;
        }
        return ans;
    }
};