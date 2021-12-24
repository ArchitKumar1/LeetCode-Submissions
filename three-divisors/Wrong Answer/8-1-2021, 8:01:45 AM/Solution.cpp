// https://leetcode.com/problems/three-divisors

class Solution {
public:
    bool isThree(int n) {
        double sq = sqrt(n);
        return n > 1 && (sq *sq == n);
    }
};