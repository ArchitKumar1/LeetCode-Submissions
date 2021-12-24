// https://leetcode.com/problems/sum-of-digits-in-base-k

class Solution {
public:
    int sumBase(int n, int k) {
        
        int ans = 0;
        for(int i = 10;~i;i--){
            long long val = (int)pow(k*1LL,i);
            ans += n / val;
            n = n % val;
            
            
        }
        return ans;
    }
};