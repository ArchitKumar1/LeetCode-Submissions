// https://leetcode.com/problems/single-number-ii

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x1 = 0,x2 = 0,mask = 0;
        for(int c : nums){
            x2 ^= x1 & c;
            x1 ^= c;
            mask = ~(x1 & x2);
            x2 &= mask;
            x1 &= mask;
        }
        return x1;
    


    }
};