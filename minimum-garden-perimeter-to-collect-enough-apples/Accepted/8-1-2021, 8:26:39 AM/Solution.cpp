// https://leetcode.com/problems/minimum-garden-perimeter-to-collect-enough-apples

class Solution {
public:
    long long minimumPerimeter(long long n) {
        long long l = 0 , h = 5e5;
        
        int ans = 0 ;
        while(l <= h){
            long long m = (l+h)/2;
            long long apples = 2LL *  (2*m +1)  * (m) * (m+1);
            if(apples >= n){
                ans = 2*m;
                h = m-1;
            }else{
                l = m + 1;
            }
            
        }
        return ans * 4;
        
    }
};