// https://leetcode.com/problems/sqrtx

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)return 0;
        long long l = 1;
        long long h = x;
        long ans = 0;
        while(l<=h){
            long mid = (l+h)>>1;
            if(mid*mid<= x){
                ans = mid;
                l = mid+1;
            }else{
                h = mid-1;
            }
        }
        return ans;
    }
};