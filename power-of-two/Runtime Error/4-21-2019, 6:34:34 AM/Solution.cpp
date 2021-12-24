// https://leetcode.com/problems/power-of-two

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 1) return 1;
         if((n & (n-1)) == 0){
             return 0;
         } else{
             return 1;
        }
    }
};