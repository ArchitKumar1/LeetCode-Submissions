// https://leetcode.com/problems/valid-perfect-square

class Solution {
public:
    bool isPerfectSquare(int num) {
        return pow(num,0.5)==int(pow(num,0.5));
    }
};