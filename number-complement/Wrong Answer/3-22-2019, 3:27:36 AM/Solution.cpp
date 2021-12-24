// https://leetcode.com/problems/number-complement

class Solution {
public:
    int findComplement(int num) {
        int upper = (long long)floor(ceil(log(num)/log(2)));
        long long  a = pow(2,upper);
        return a- 1- num;
    }
};