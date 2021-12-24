// https://leetcode.com/problems/remove-element

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto it = nums.begin();
        for(int i=0;i<nums.size();i++){
            if(nums[i] == val){
                nums.erase(it+i);
                i--;
            }
        }
        return nums.size();
    }
};