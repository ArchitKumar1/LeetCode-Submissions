// https://leetcode.com/problems/consecutive-numbers-sum

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        if(N == 1) return 0;
        long long int l =0 ;
        long long int h = 1e9;
        N--;
        int ans;
        while(l<=h){
            long long mid = (l+h)>>1;
            if(mid*(mid+1)/2 <= N){
                ans = mid;
                l = mid+1;
            }else{
                h = mid-1;
            }
        }
        return ans;
        
    }
};