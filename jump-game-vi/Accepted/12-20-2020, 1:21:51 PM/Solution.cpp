// https://leetcode.com/problems/jump-game-vi

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
    vector<int> dp(nums.size(), INT_MIN);
    dp[0] = nums[0];
    for (auto i = 0; i < nums.size(); ++i)
        for (auto j = 1; j <= k && i + j < nums.size(); ++j) {
            dp[i + j] = max(dp[i + j], dp[i] + nums[i + j]);
            if (nums[i + j] >= 0)
                break;
        }
    return dp.back();
}
};