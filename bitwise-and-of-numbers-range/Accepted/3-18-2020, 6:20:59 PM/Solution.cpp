// https://leetcode.com/problems/bitwise-and-of-numbers-range

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans = 0;
        for(int i = 31;i>=0;i--){
            int a = ((1<<i)&m)>=1;
            int b = ((1<<i)&n)>=1;
            if(a == 1 && b == 1){
                ans += (1<<i);
            }else if(a == 0 && b == 0){
                continue;
            }else{
                break;
            }
        }
        return ans;
    }
};