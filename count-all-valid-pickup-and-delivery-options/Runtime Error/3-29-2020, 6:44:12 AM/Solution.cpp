// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options

class Solution {
public:
    int countOrders(int n) {
        int prev = 1;
        int mod = 1e9+7;
        for(int i = 2;i<=n;i++){
            int curr = (i-1)*2+2;
            prev = (long long) (prev*(curr)%mod*(curr-1))/2 %mod;
        }
        return prev;
    }
};