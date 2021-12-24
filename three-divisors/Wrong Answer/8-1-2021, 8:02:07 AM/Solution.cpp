// https://leetcode.com/problems/three-divisors

class Solution {
public:
    bool isThree(int n) {
        int sq = sqrt(n);
        return n > 1 && (sq *sq == n);
    }
};