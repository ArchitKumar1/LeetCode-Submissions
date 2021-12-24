// https://leetcode.com/problems/arranging-coins

class Solution {
public:
    int arrangeCoins(int n) {
        for(int i=1;i<=n;i++){
            if( i*(i+1)/2 > n) 
                return i -1;
        }
        return 1;
    }
};