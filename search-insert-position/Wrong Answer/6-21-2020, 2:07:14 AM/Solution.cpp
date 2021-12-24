// https://leetcode.com/problems/search-insert-position

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto up = upper_bound(nums.begin(),nums.end(),target);
        if(up == nums.end()){
            return nums.size();
        }else{
            auto low = lower_bound(nums.begin(),nums.end(),target);
            return (low - nums.begin());
        }
    }
};