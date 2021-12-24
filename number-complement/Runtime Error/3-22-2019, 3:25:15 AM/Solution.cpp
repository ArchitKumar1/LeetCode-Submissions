// https://leetcode.com/problems/number-complement

class Solution {
public:
    int findComplement(int num) {
        int upper = log(num)/log(2);
        int a = pow(2,upper+1);
        return a- 1- num;
    }
};