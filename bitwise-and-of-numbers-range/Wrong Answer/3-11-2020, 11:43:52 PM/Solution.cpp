// https://leetcode.com/problems/bitwise-and-of-numbers-range

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans = 0;
        for(int i = 0;i<32;i++){
            if( ((1<<i)&m )&& ((1<<i)&n)) ans += (1<<(i));
        }
        return ans;
    }
};