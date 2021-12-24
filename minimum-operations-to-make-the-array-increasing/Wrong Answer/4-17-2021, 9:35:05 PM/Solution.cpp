// https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for(int i = 1;i<nums.size();i++){
            ans += max(nums[i-1]+1-nums[i],0);
            nums[i] = max(nums[i]+1,nums[i]);
        }
        return ans;
    }
};