// https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays

class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int ans = 0;
        
        auto solve = [&](int x) -> int64_t{
            // counts all possible pairs whos product is less than x
            cout << endl;
            int64_t cnt = 0;
            for(int c : nums1){
                if(c >= 0){
                    int64_t ans = 0;
                    int64_t l = 0;
                    int64_t h = nums2.size()-1;
                    while(l <= h){
                        int64_t m = (l+h)/2;
                        if(1LL * nums2[m] * c <= x){
                            ans = m + 1;
                            l = m + 1;
                        }else{
                            h = m - 1;
                        }
                    }
                    cout << c << " B " << ans << endl;
                }else{
                    int64_t ans = 0;
                    int64_t l = 0;
                    int64_t h = nums2.size()-1;
                    while(l <= h){
                        int64_t m = (l+h)/2;
                        if(1LL * nums2[m] * c <= x){
                            ans = m + 1;
                            l = m + 1;
                        }else{
                            h = m - 1;
                        }
                    }
                    ans = nums2.size()-ans;
                    cout << c << " B " << ans << endl;
                }
                cnt += ans;
            }
            cout << endl;
            return cnt;
        };
        
        int fans = 0;
        int64_t l = -1e10;
        int64_t h = 1e10;
        while(l <= h){
            int m = (l+h)/2;
            cout << m << " " << solve(m) << endl;
            if(solve(m) >= k){
                fans = m;
                h = m - 1;
            }else{
                l = m + 1;
            }
        }
        return fans;
    }
};