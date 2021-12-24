// https://leetcode.com/problems/maximum-product-of-three-numbers

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int length=nums.size();
        long long m=max(nums[0]*nums[1]*nums[length-1],nums[length-1]*nums[length-2]*nums[length-3])    ;
        return m;                                             
    }
};