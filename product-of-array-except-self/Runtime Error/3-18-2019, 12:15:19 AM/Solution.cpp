// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int a = 1;
        for(auto c : nums)
            a*= c;
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            ans[i] = a/nums[i];
        }
        return ans;
    }
};