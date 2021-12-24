// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        auto lb = lower_bound(nums.begin(),nums.end(),target);
        auto ub = upper_bound(nums.begin(),nums.end(),target);

        ans[0] = lb==nums.end() ? -1 : (int)(lb - nums.begin());
        ans[1] = ub==nums.end() ? -1 : (int)(ub - nums.begin()) - 1;
        return ans;
    }
};