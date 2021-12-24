// https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements

namespace MATH {
    template <class T>T pow_mod(T a,T b,long long m){
        a %= m;
        long long res = 1;
        while(b){ 
            if(b&1) res =((long long)res*a)%m;
            a = ((long long)a*a)%m;b >>=1;
        }
        return res;
    }
    long long pow_mod2(long long a, long long b,long long m){
        if(b == 1) return a;
        return ((b&1 ? a%m : 1LL) * (pow_mod2(a*a % m,b/2,m)) % m) % m ;
    }
}
using namespace MATH;
class Solution {
public:
    int minNonZeroProduct(int p) {
        long long x = pow(2LL,p);
        if(p == 1) return 1;
        int M = 1e9+7;
        return (x-1) % M  * ( pow_mod2(x-2,x/2 - 1,M) % M ) % M;
    }
};