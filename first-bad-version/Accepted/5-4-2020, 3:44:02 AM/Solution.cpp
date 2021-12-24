// https://leetcode.com/problems/first-bad-version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
    #define LL long long int
public:
    int firstBadVersion(int n) {
        LL l =0 ;
        LL h = INT_MAX;
        LL ans =-1;
        while(l<=h){
            LL mid = (l+h)/2;
            if(isBadVersion(mid) == 1){
                ans = mid;
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};