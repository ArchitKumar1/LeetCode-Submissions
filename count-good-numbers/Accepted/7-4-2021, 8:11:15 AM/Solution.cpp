// https://leetcode.com/problems/count-good-numbers

const int MOD = 1e9+7;
class Solution {
public:
    long long pow_mod(long long a,long long b,long long m= MOD){
        long long res = 1LL;
        while(b){ 
            if(b&1) res =((long long)res*a)%m;
            a = ((long long)a*a)%m;b >>=1;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long ans = 0;
        int ans1 = pow_mod(5,(n&1) + n/2,MOD);
        int ans2 = pow_mod(4,n/2,MOD);
        
        return 1LL* ans1 * ans2 % MOD;
        
        
    }
};