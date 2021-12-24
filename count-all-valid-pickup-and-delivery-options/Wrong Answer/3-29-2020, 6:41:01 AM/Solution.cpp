// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options

class Solution {
public:
    int countOrders(int n) {
        int prev = 1;
        int mod = 1e9+7;
        for(int i = 2;i<=n;i++){
            int curr = prev*2+2;
            prev = (long long) ((curr)*(curr-1))/2 %mod;
            cout << prev << endl;
        }
        return prev;
    }
};