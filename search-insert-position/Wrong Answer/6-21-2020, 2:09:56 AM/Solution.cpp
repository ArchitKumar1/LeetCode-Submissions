// https://leetcode.com/problems/search-insert-position

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto low = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        if(nums[low] == target){
            return low;
        }else{
            return low+1;
        }
    }
};