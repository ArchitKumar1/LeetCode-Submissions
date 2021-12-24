// https://leetcode.com/problems/sum-of-subarray-ranges

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for(int i = 0;i < n;i++){
            int mi = INT_MAX,ma = INT_MIN;
            for(int j = i;j < n;j++){
                mi = min(mi,nums[j]);
                ma = max(ma,nums[j]);
                ans += (ma - mi);
            }
        }
        return ans;
    }
};