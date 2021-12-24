// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsofar=nums[0];
        int currentmax=nums[0];
        for(int i=0; i<nums.size();i++){
            currentmax=max(nums[i],currentmax+ nums[i]);
            maxsofar=max(maxsofar,currentmax);
        }
        return maxsofar;
    }
};