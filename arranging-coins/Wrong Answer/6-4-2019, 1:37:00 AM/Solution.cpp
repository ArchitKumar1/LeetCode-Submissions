// https://leetcode.com/problems/arranging-coins

class Solution {
public:
    int arrangeCoins(int n) {
        for(int i=1;i<=n;i++){
            if( (long long int) i*(i+1)/2 > (long long int)n) 
                return i -1;
        }
        return 0;
    }
};