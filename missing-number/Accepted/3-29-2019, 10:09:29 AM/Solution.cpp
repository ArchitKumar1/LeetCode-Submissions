// https://leetcode.com/problems/missing-number

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = n*(n+1)/2;
        for(auto n : nums)
            ans -= n;
        return ans;
    }
};