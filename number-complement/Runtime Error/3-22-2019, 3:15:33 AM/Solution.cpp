// https://leetcode.com/problems/number-complement

class Solution {
public:
    int findComplement(int num) {
        int upper = floor(ceil(1.0*log(num)/log(2)));
        int a = pow(2,upper);
        return a- 1- num;
    }
};