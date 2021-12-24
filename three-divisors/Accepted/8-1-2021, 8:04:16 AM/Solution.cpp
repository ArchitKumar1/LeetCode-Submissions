// https://leetcode.com/problems/three-divisors

class Solution {
public:
    bool isThree(int n) {
        int sq = sqrt(n);
        if(sq * sq != n) return 0;
        bool ans = 1;
        for(int i = 2 ; i*i <= sq;i++){
            if(sq%i == 0){
                ans = 0;
            }
        }
        return n > 1 && ans;
    }
};