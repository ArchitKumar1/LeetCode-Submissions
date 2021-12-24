// https://leetcode.com/problems/valid-perfect-square

class Solution {
    #define LL long long int
public:
    bool isPerfectSquare(int num) {
        
        LL l = 0;
        LL h = 1e5;
        LL ans = 0;
        while(l<=h){
            LL mid = (l+h)/2;
            
            if(mid*mid==num){
                ans = mid;
                break;
            }else if(mid*mid > num){
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans >= 1;
    }
};