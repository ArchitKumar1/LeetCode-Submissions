// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        int L = 31;
        for(int i = 0;i<=L;i++){
            int x = a&(1 << i);
            int y = b&(1 << i);
            int z = c&(1 << i);
            if(z){
                if(x == 0 && y == 0){
                    ans += 1;
                }
            }else{
                ans += ((x>0) + (y >0));
            }
        }
        return ans;
    }
};