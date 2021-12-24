// https://leetcode.com/problems/reverse-bits

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int a[32]= {0};
        for(int i=0;i<32;i++){
            if( (1 << i) & n){
                a[i] = 1;
            }
        }
        int ans = 0;
        int pos = 31;
        for(int i=0;i<32;i++){
            if(a[i]){
                ans += pow(2,pos);
            }
            pos--;
        }
        return ans;
    }
};