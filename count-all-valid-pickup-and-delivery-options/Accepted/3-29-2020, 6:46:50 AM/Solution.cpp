// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options

class Solution {
public:
    int countOrders(int n) {
        long long prev = 1;
        long long mod = 1e9+7;
        for(int i = 2;i<=n;i++){
            long long curr = (i-1)*2+2;
             curr = ((long long )(curr)*(curr-1)/2)%mod;
            prev = (long long) (prev*curr) %mod;
        }
        return prev;
    }
};