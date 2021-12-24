// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers

class Solution {
public:
    
    long long int ans = 0;
    int mod = 1e9+7;

    int l= 0;
    int concatenatedBinary(int n) {
        for(int i = 1;i<=n;i++){
            int l = (int)log2(i)+1;
            ans = (ans << l)%mod;
            ans += i;
        }
        return ans;
    }
};