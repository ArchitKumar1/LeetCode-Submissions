// https://leetcode.com/problems/guess-number-higher-or-lower

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int ans = 0;
        
        long long int  l = 0,h = INT_MAX;
        
        while(l <= h){
            long long int m = (l+h)/2;
            int G = guess(m);
            if(G== 0){
                ans = m;break;
            }else if(G == 1){
                l = m + 1;
            }else{
                h = m - 1;
            }
        }
        return ans;
    }
};