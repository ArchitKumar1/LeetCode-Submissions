// https://leetcode.com/problems/arranging-coins

class Solution {
public:
    int arrangeCoins(int n) {
        int x = 0;
        while(x*(x+1) <= 2*n){
            ++x;
        }
        return x-1;
    }
};