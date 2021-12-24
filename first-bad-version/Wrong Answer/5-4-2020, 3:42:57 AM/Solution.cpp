// https://leetcode.com/problems/first-bad-version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l =0 ;
        int h = 1e9;
        int ans =-1;
        while(l<=h){
            int mid = (l+h)/2;
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