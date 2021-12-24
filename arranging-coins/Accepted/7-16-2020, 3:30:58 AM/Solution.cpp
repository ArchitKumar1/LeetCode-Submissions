// https://leetcode.com/problems/arranging-coins

class Solution {
public:
    int arrangeCoins(int n) {
        int x = 0;
        while(1LL*x*(x+1) <= 2LL*n){
            ++x;
        }
        return x-1;
    }
};