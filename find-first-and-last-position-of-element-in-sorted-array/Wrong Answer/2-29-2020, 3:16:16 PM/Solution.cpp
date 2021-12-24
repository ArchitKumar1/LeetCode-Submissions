// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int t) {
        vector<int> ans;
        int a = lower_bound(nums.begin(),nums.end(),t) - nums.begin();
        ans.push_back(a);
        a = upper_bound(nums.begin(),nums.end(),t) - nums.begin();
        ans.push_back(a-1);
        return ans;
    }
};