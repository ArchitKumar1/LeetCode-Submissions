// https://leetcode.com/problems/power-of-two

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
         if(n > 0 && (n & (n-1)) == 0){
             return 0;
         } else{
             return 1;
        }
    }
};